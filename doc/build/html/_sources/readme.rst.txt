Cryptosuite2
************

.. contents::

Links
=====

- The `code is here <https://github.com/daknuett/cryptosuite2>`_.
- The `docs are here <https://daknuett.github.io/cryptosuite2/index.html>`_.

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

Take a look at the `docs
<https://daknuett.github.io/cryptosuite2/usage.html>`_.


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
