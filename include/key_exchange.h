// header file for key exchange

#ifndef KEY_EXCHANGE_H
#define KEY_EXCHANGE_H

#include "elliptic_curve.h"
#include <random>

int64_t generate_private_key(int64_t n);

EllipticCurvePoint compute_public_key(int64_t private_key, const EllipticCurvePoint &G, int64_t a, int64_t p);

EllipticCurvePoint compute_shared_secret(int64_t private_key, const EllipticCurvePoint &public_other, int64_t a, int64_t p);

#endif
