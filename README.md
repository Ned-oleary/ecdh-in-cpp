# ecdh-in-cpp

an implementation of elliptic curve diffie helman from scratch in c++

just written to make sure I really understood the mechanics -- no one should *ever* use this

it's a dumb implementation for a few reasons:
* doesn't check whether points actually lie on the curve in question (it will just compute incorrect shared secrets)
* doesn't work for large integers
* it's probably slow
* it probably has a few bugs that I haven't found yet -- I didn't test this very much

it does seemingly work (sometimes) for very simple curves and very small prime numbers. it definitively does *not* work for real-world ECs like secp256k1

I probably won't revisit this any time soon

