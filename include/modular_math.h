// header file for modular math

#ifndef MODULAR_MATH_H
#define MODULAR_MATH_H

#include <cstdint>

int64_t modular_addition(int64_t a, int64_t b, int64_t p);

int64_t modular_subtraction(int64_t a, int64_t b, int64_t p);

int64_t modular_multiplication(int64_t a, int64_t b, int64_t p);

int64_t modular_exponentiation(int64_t a, int64_t b, int64_t p);

int64_t modular_inverse(int64_t a, int64_t p);

#endif