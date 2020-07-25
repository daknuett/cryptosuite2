Usage with Arduino
******************

.. contents::


General
:::::::

Optimization and Disabling Code Objects
=======================================

Code objects eat up your precious flash memory. It is
therefore important to disable all the code you do not need.

This can be done using the file ``config.h`` in the library
folder of cryptosuite2. This file includes the module
configuration first so you can overwrite the module
configuration.

The first thing one should do is to disable modules you do
not need. This is done by defining ``SHA256_DISABLED`` or
``SHA1_DISABLED``. All code for these modules will then be
excluded.

Also you can disable *HMAC* to save both flash memory and
RAM using ``#undef SHA256_ENABLE_HMAC`` and 
``#undef SHA1_ENABLE_HMAC``.

The last thing one can do is to disable the ``C++``
interface (see the sections below about how to use the ``C``
interface) by defining ``SHA256_DISABLE_WRAPPER`` and
``SHA1_DISABLE_WRAPPER``.


Sha256
::::::

Simple Usage
============

cryptosuite2 brings a C++ interface that can be used by
Arduino users easily.


After including the header one can use the class
``Sha256Wrapper`` with the methods

``init(void): void``
	Initializes the ``Sha256Wrapper`` for hashing.
	Must be invoked before hashing.
``result(void): uint8_t *``
	Returns **a reference** to the hash. Once this
	method has been called ``init`` must be invoked
	again.
``write(various types): size_t``
	Write data into the hasher.

If the preprocessor macro ``SHA256_ENABLE_HMAC`` in
``config.h`` is set (which it is by default) [1]_ the
following methods are available:

``initHmac(const uint8_t * secret, unsigned int secretLength): void``
	Initializes the ``Sha256Wrapper`` for HMAC.
``resultHmac(void): uint8_t *``
	Returns **a reference** to the hash. Once this
	method has been called ``init`` must be invoked
	again.

``sha256.h`` also brings a global hasher: ``Sha256``.

Example:

.. code-block:: c++

	#include "sha256.h"

	// read data from the serial interface and print the
	// hash to the serial

	void setup(void)
	{
		Serial.begin(9600);
	}

	void loop(void)
	{
		if(!Serial.available())
		{
			return;
		}
		Sha256.init();

		Sha256.print(Serial.read());

		uint8_t * result = Sha256.result();

		Serial.print("Hash:\n");

		for (int i = 0; i < 32; i++) {
			Serial.print("0123456789abcdef"[result[i] >> 4]);
			Serial.print("0123456789abcdef"[result[i] & 0xf]);
		}
		Serial.print("\n");
	}


The same way *HMAC* can be used:

.. code-block:: c++

	#include "sha256.h"

	void setup(void)
	{
		Serial.begin(9600);

		// this is actually the RFC4231 4.3 test

		Sha256.initHmac((uint8_t * ) "Jefe", 4);
		Sha256.print("what do ya want for nothing?");
		uint8_t * result = Sha256.resultHmac();

		Serial.println("Expect: 5bdcc146bf60754e6a042426089575c75a003f089d2739839dec58b964ec3843");
		Serial.print(  "Got   : ");
		for (int i = 0; i < 32; i++) {
			Serial.print("0123456789abcdef"[result[i] >> 4]);
			Serial.print("0123456789abcdef"[result[i] & 0xf]);
		}
		Serial.print("\n");
	}


	void loop(void)
	{}

Extended
========

Disabling the ``C++`` Wrapper
-----------------------------

The ``C++`` wrapper increases the overhead and eats up some
RAM. So one can disable the wrapper by defining
``SHA256_DISABLE_WRAPPER`` in ``config.h``

.. code-block:: c++

	#define SHA256_DISABLE_WRAPPER


Instantiating a new Hasher
--------------------------

A new hasher can be created by calling ``sha256_hasher_new``:

.. code-block:: c++


	#define SHA256_DISABLE_WRAPPER
	#include "sha256.h"


	sha256_hasher_t hasher;

	void setup(void)
	{
		 hasher = sha256_hasher_new();
		 Serial.begin(9600);
	}


Writing to the Hasher
---------------------

Before one writes to the hasher he should invoke
``sha256_hasher_init``, although this function has been
called by ``sha256_hasher_new``. Then he can write safely:

.. code-block:: c++

	void loop(void)
	{
		sha256_hasher_init(hasher);

		sha256_hasher_write(hasher, "abc", 3);
	}

Obtaining the Result and free'ing the Hasher
--------------------------------------------

.. code-block:: c++

	void loop(void)
	{
		sha256_hasher_init(hasher);
		sha256_hasher_write(hasher, "abc", 3);

		uint8_t * result;
		result = sha256_hasher_gethash(hasher);

		Serial.print("EXPECT: ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad\n");
		Serial.print("GOT   : ");
		for (int i = 0; i < 32; i++) {
			Serial.print("0123456789abcdef"[result[i] >> 4]);
			Serial.print("0123456789abcdef"[result[i] & 0xf]);
		}
		Serial.print("\n");

		// do not actually delete the hasher
		// we are inside loop

		// sha256_hasher_del(hasher);

	}


API Doc
-------

``sha256_hasher_new(void): sha256_hasher_t``
	Allocate and initialize a new hasher.
``sha256_hasher_del(sha256_hasher_t hasher): void``
	Free the hasher.
``sha256_hasher_init(sha256_hasher_t hasher)``
	(Re-) Initialize the hasher for hashing.
``sha256_hasher_putc(sha256_hasher_t hasher, uint8_t byte): int``
	Put ``byte`` to the hasher. Follows the standard
	``putc`` conventions.
``sha256_hasher_gethash(sha256_hasher_t hasher): uint8_t *``
	Returns **a reference** of the hash. One **must
	not** free the result. This modifies the state of
	the hasher. Once this function has been called,
	``sha256_hasher_init`` must be invoked or
	``sha256_hasher_putc`` will fail.
``sha256_hasher_write(sha256_hasher_t hasher, const void * buf, size_t count): ssize_t``
	Writes to the hasher. Follows the standard ``write``
	conventions and uses ``sha256_hasher_putc``.

If ``SHA256_ENABLE_HMAC`` is defined in ``config.h``
also the following functions are available:

``sha256_hasher_init_hmac(sha256_hasher_t hasher, const uint8_t * key, size_t key_len): void``
	Initialize the hasher for *HMAC*. Invokes
	``sha256_hasher_init``.
``sha256_hasher_gethmac(sha256_hasher_t hasher): uint8_t *``
	Returns **a reference** of the hash. One **must
	not** free the result. This modifies the state of
	the hasher. Once this function has been called,
	``sha256_hasher_init`` must be invoked or
	``sha256_hasher_putc`` will fail.


Sha1
::::

Simple Usage
============

cryptosuite2 brings a C++ interface that can be used by
Arduino users easily.


After including the header one can use the class
``Sha1Wrapper`` with the methods

``init(void): void``
	Initializes the ``Sha1Wrapper`` for hashing.
	Must be invoked before hashing.
``result(void): uint8_t *``
	Returns **a reference** to the hash. Once this
	method has been called ``init`` must be invoked
	again.
``write(various types): size_t``
	Write data into the hasher.

If the preprocessor macro ``SHA1_ENABLE_HMAC`` in
``config.h`` is set (which it is by default) [1]_ the
following methods are available:

``initHmac(const uint8_t * secret, unsigned int secretLength): void``
	Initializes the ``Sha1Wrapper`` for HMAC.
``resultHmac(void): uint8_t *``
	Returns **a reference** to the hash. Once this
	method has been called ``init`` must be invoked
	again.

``sha1.h`` also brings a global hasher: ``Sha1``.

Example:

.. code-block:: c++

	#include "sha1.h"

	// read data from the serial interface and print the
	// hash to the serial

	void setup(void)
	{
		Serial.begin(9600);
	}

	void loop(void)
	{
		if(!Serial.available())
		{
			return;
		}
		Sha1.init();

		Sha1.print(Serial.read());

		uint8_t * result = Sha1.result();

		Serial.print("Hash:\n");

		for (int i = 0; i < 10; i++) {
			Serial.print("0123456789abcdef"[result[i] >> 4]);
			Serial.print("0123456789abcdef"[result[i] & 0xf]);
		}
		Serial.print("\n");
	}


The same way *HMAC* can be used:

.. code-block:: c++

	#include "sha1.h"

	void setup(void)
	{
		Serial.begin(9600);

		// this is actually the RFC4231 4.3 test

		Sha1.initHmac((uint8_t * ) "Jefe", 4);
		Sha1.print("what do ya want for nothing?");
		uint8_t * result = Sha1.resultHmac();

		Serial.println("Expect: b0344c61d8db38535ca8afceaf0bf12b881dc200c9833da726e9376c2e32cff7");
		Serial.print(  "Got   : ");
		for (int i = 0; i < 10; i++) {
			Serial.print("0123456789abcdef"[result[i] >> 4]);
			Serial.print("0123456789abcdef"[result[i] & 0xf]);
		}
		Serial.print("\n");
	}


	void loop(void)
	{}

Extended
========

Disabling the ``C++`` Wrapper
-----------------------------

The ``C++`` wrapper increases the overhead and eats up some
RAM. So one can disable the wrapper by defining
``SHA1_DISABLE_WRAPPER`` in ``config.h``:

.. code-block:: c++

	#define SHA1_DISABLE_WRAPPER


Instantiating a new Hasher
--------------------------

A new hasher can be created by calling ``sha1_hasher_new``:

.. code-block:: c++


	#define SHA1_DISABLE_WRAPPER
	#include "sha1.h"


	sha1_hasher_t hasher;

	void setup(void)
	{
		 hasher = sha1_hasher_new();
		 Serial.begin(9600);
	}


Writing to the Hasher
---------------------

Before one writes to the hasher he should invoke
``sha1_hasher_init``, although this function has been
called by ``sha1_hasher_new``. Then he can write safely:

.. code-block:: c++

	void loop(void)
	{
		sha1_hasher_init(hasher);

		sha1_hasher_write(hasher, "abc", 3);
	}

Obtaining the Result and free'ing the Hasher
--------------------------------------------

.. code-block:: c++

	void loop(void)
	{
		sha1_hasher_init(hasher);
		sha1_hasher_write(hasher, "abc", 3);

		uint8_t * result;
		result = sha1_hasher_gethash(hasher);

		Serial.print("EXPECT: ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad\n");
		Serial.print("GOT   : ");
		for (int i = 0; i < 10; i++) {
			Serial.print("0123456789abcdef"[result[i] >> 4]);
			Serial.print("0123456789abcdef"[result[i] & 0xf]);
		}
		Serial.print("\n");

		// do not actually delete the hasher
		// we are inside loop

		// sha1_hasher_del(hasher);

	}


API Doc
-------

``sha1_hasher_new(void): sha1_hasher_t``
	Allocate and initialize a new hasher.
``sha1_hasher_del(sha1_hasher_t hasher): void``
	Free the hasher.
``sha1_hasher_init(sha1_hasher_t hasher)``
	(Re-) Initialize the hasher for hashing.
``sha1_hasher_putc(sha1_hasher_t hasher, uint8_t byte): int``
	Put ``byte`` to the hasher. Follows the standard
	``putc`` conventions.
``sha1_hasher_gethash(sha1_hasher_t hasher): uint8_t *``
	Returns **a reference** of the hash. One **must
	not** free the result. This modifies the state of
	the hasher. Once this function has been called,
	``sha1_hasher_init`` must be invoked or
	``sha1_hasher_putc`` will fail.
``sha1_hasher_write(sha1_hasher_t hasher, const void * buf, size_t count): ssize_t``
	Writes to the hasher. Follows the standard ``write``
	conventions and uses ``sha1_hasher_putc``.

If ``SHA1_ENABLE_HMAC`` is defined in ``config.h``
also the following functions are available:

``sha1_hasher_init_hmac(sha1_hasher_t hasher, const uint8_t * key, size_t key_len): void``
	Initialize the hasher for *HMAC*. Invokes
	``sha1_hasher_init``.
``sha1_hasher_gethmac(sha1_hasher_t hasher): uint8_t *``
	Returns **a reference** of the hash. One **must
	not** free the result. This modifies the state of
	the hasher. Once this function has been called,
	``sha1_hasher_init`` must be invoked or
	``sha1_hasher_putc`` will fail.





.. [1] ``config.h`` includes ``shaX/default.h``. Some
   configuration is done here. When using the Arduino
   interface one should only edit ``config.h``.
