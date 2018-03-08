Cryptosuite2
************

.. contents::

What Is Cryptosuite2?
=====================

Cryptosuite2 is a (more or less) drop in replacement for
https://github.com/Cathedrow/Cryptosuite. It currently
provides SHA256 and HMAC-SHA256. 

Install
=======

- Download the library.
- Copy ``cryptosuite2/sha`` to ``~/sketchbook/libraries``
  (``cp -rv cryptosuite2/sha ~/sketchbook/libraries``)

Usage
=====

Simple
------

Just include the header and use the built-in wrapper:

.. code:: Cpp

	#include "sha256.h"

	void loop(){
		 Sha256.init();
		 Sha256.print("abc");
		 uint8_t * hash = Sha256.result();
	}
	void setup(){}


Extended
--------

It is possible to use the pure ``C`` library and omit the
``C++`` wrapper. This uses less RAM.

Also it is possible to have several hashers at a time.

To be done.


Gotchas
-------

- Once ``Sha256.result()`` or ``Sha256.resultHmac()`` 
  (or ``sha256_hasher_gethash()``,
  ``sha256_hasher_gethmac()``, ``sha256_hasher_pad()``)
  have been invoked ``Sha256.init()`` (or
  ``sha256_hasher_init()``) must be invoked!

Todos
=====

- Add examples.
- Add ``sha1`` and other algorithms.

Contributing
============

Contributions are welcome!

Just add yourself in the ``contributors.yml`` file and send
a pull request.

All contributions must be licensed under the GNU GPLv3. This
is just because keeping track of various licenses is a pain
in the ass.
