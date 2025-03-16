#include "../include/elliptic_curve.h"


// elliptic curve point addition is special! this is weird!
// the line drawn through any two points P, Q on elliptic curve will intersect at exactly one point -R
// we reflect -R over the x axis to derive the output of the addition P + Q, i.e. P + Q == R
// the sum of three colinear points on an elliptic curve is always zero in the group law!
EllipticCurvePoint elliptic_curve_add(const EllipticCurvePoint &P, const EllipticCurvePoint &Q, int64_t a, int64_t p){
    if (P.is_infinity) return Q;
    if (Q.is_infinity) return P;

    // if points mirror by reflection over X axis
    // have same X, but are not the same point, i.e. not the same Y unless intersect X axis
    if (P.x == Q.x && (P.y != Q.y || P.y == 0)){
        return EllipticCurvePoint(); // note: isInfinity defaults to True
    }

    int64_t line_slope;

    // if it's the same point, don't use normal elliptic_curve_add algo
    // the line is tangent to the curve
    if (P.x == Q.x && P.y == Q.y){
        return elliptic_curve_double(P, a, p);
    }
    else{
        int64_t numerator = modular_subtraction(Q.y, P.y, p);
        int64_t denominator = modular_subtraction(Q.x, P.x, p);
        int64_t denominator_inverse = modular_inverse(denominator, p);
        line_slope = modular_multiplication(numerator, denominator_inverse, p);
    }

    int64_t output_x = modular_subtraction(modular_subtraction(modular_exponentiation(line_slope, 2, p), P.x, p), Q.x, p);
    int64_t output_y = modular_subtraction(modular_multiplication(line_slope, modular_subtraction(P.x, output_x, p), p), P.y, p);

    return EllipticCurvePoint(output_x, output_y);

};

// we need the slope of the *tangent* line to the elliptic curve at P
// we have to do some (basic) calculus! fun stuff
EllipticCurvePoint elliptic_curve_double(const EllipticCurvePoint &P, int64_t a, int64_t p){

    // check for special case first!
    if (P.is_infinity || P.y == 0){
        return EllipticCurvePoint();
    }

    // slope comes from the derivative of y w.r.t. x, which gives (3x^2 + a) / 2y mod p
    int64_t numerator = modular_addition(modular_multiplication(3, modular_exponentiation(P.x, 2, p), p), a, p);
    int64_t denominator = modular_multiplication(2, P.y, p);
    int64_t denominator_inverse = modular_inverse(denominator, p);
    int64_t line_slope = modular_multiplication(numerator, denominator_inverse, p);

    int64_t output_x = modular_subtraction(modular_exponentiation(line_slope, 2, p), modular_multiplication(2, P.x, p), p);
    int64_t output_y = modular_subtraction(modular_multiplication(line_slope, modular_subtraction(P.x, output_x, p), p), P.y, p);

    return EllipticCurvePoint(output_x, output_y);

};

// now we need a function for scalar multiplication of an elliptic curve point, i.e. k * P for some P on EC
// kP = P + P + P ... P 
// we use the binary representation of k, traversing the bits from right to left

EllipticCurvePoint elliptic_curve_multiply(int64_t k, const EllipticCurvePoint &P, int64_t a, int64_t p){
    EllipticCurvePoint accumulated_point;
    EllipticCurvePoint base_point = P; 
    while ( k > 0 ){
        if ( k & 1 ){
            accumulated_point = elliptic_curve_add(accumulated_point, base_point, a, p); // accumulate IFF we see a 1 bit at rightmost
        }
        base_point = elliptic_curve_double(base_point, a, p); // capture increasing exponent as we move toward the left bits
        k = k >> 1; // right shift is equivalent to division by two, lets us traverse the bits right to left by looking at rightmost
    }

    return accumulated_point;
};
