// header file for elliptic curve
// we start with secp256k1: https://en.bitcoin.it/wiki/Secp256k1
// F_p = 2^256 - 2^32 - 2^9 - 2^8 - 2^7 - 2^6 - 2^4 - 1

#ifndef ELLIPTIC_CURVE_H
#define ELLIPTIC_CURVE_H

#include <cstdint>
#include "modular_math.h"

struct EllipticCurvePoint {
    int64_t x;
    int64_t y;
    bool is_infinity;

    // don't really like this syntax but it's efficient -- not using garbage values
    // https://en.cppreference.com/w/cpp/language/list_initialization
    EllipticCurvePoint() : x(0), y(0), is_infinity(true) {}  
    EllipticCurvePoint(int64_t x, int64_t y) : x(x), y(y), is_infinity(false) {}
};

EllipticCurvePoint elliptic_curve_add(const EllipticCurvePoint &P, const EllipticCurvePoint &Q, int64_t a, int64_t p);
EllipticCurvePoint elliptic_curve_double(const EllipticCurvePoint &P, int64_t a, int64_t p);
EllipticCurvePoint elliptic_curve_multiply(int64_t k, const EllipticCurvePoint &P, int64_t a, int64_t p);

#endif
