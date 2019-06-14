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

Using the ZIP for Arduino
-------------------------

Download the latest ZIP release from `the release page <https://github.com/daknuett/cryptosuite2/releases/>`_
and install it using the Arduino IDE.

Manually
--------

- Download the library.
- Copy ``cryptosuite2/sha`` to ``~/sketchbook/libraries``
  (``cp -rv cryptosuite2/sha ~/sketchbook/libraries``)
  or ``~/Arduino/libraries`` (``cp -rv cryptosuite2/sha ~/Arduino/libraries``)


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

You can ask for further features, but right now it seems
like all the required stuff is running.

Contributing
============

Contributions are welcome!

Just add yourself in the ``contributors.yml`` file and send
a pull request.

All contributions must be licensed under the GNU GPLv3. This
is just because keeping track of various licenses is a pain
in the ass.

Support
=======

I can give you some assistance in general, but do not expect
too much. I have a lot to do. 
Also I will fix bugs, but it might take a while.

If you want to speed up my support/my fixes `buy me a beer
<https://paypal.me/daknuett/5>`_. Also you are welcome to 
`support me <https://paypal.me/daknuett/10>`_ if you think it 
is a good idea to do so.

(An I kinda wanted to test these paypal links :-P)
