Usage as a C Library
********************

.. contents::

SHA256
::::::

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

If ``SHA256_ENABLE_HMAC`` is defined in ``sha256/default.h``
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

SHA1
::::
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

If ``SHA1_ENABLE_HMAC`` is defined in ``sha1/default.h``
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
