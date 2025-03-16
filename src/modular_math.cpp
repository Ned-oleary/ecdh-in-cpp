#include "../include/modular_math.h"

int64_t modular_addition(int64_t a, int64_t b, int64_t p){
    return (a + b) % p;
};

int64_t modular_subtraction(int64_t a, int64_t b, int64_t p){
    return (a - b) % p;
};

int64_t modular_multiplication(int64_t a, int64_t b, int64_t p){
    return (a * b) % p;
};

// this one isn't obvious
// we're doing exponentiation by squaring
int64_t modular_exponentiation(int64_t base, int64_t exponent, int64_t p){
    int64_t accumulated_value = 1;
    base = base % p; // note base = kp + n for some k,p ==> (kp + n) ^ exp == p(k^exp ... ) + n^exp
    while (exponent > 0) {
        if (exponent % 2 == 1){
            accumulated_value = (accumulated_value * base) % p;
        }
        base = (base * base) % p;
        exponent = exponent / 2;
    }
    return accumulated_value;
};


// note: uses Fermat's Little Theroem
// p must therefore be a prime number!
int64_t modular_inverse(int64_t a, int64_t p){
    int64_t accumulated_value = 1;
    int64_t base = a;
    int64_t exponent = p - 2;
    while (exponent > 0) {
        if (exponent % 2 == 1){
            accumulated_value = (accumulated_value * base) * p;
        }
        base = (base * base) % p;
        exponent = exponent / 2;
    }
    return accumulated_value;
};