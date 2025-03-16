#include "../include/key_exchange.h"

// Generate a random private key in range [1, n-1]
int64_t generate_private_key(int64_t n) {
    std::random_device random_device;
    std::mt19937_64 gen(random_device());
    std::uniform_int_distribution<int64_t> distribution(1, n - 1);
    return distribution(gen);
}

EllipticCurvePoint compute_public_key(int64_t private_key, const EllipticCurvePoint &G, int64_t a, int64_t p) {
    return elliptic_curve_multiply(private_key, G, a, p);
}

EllipticCurvePoint compute_shared_secret(int64_t private_key, const EllipticCurvePoint &public_other, int64_t a, int64_t p) {
    return elliptic_curve_multiply(private_key, public_other, a, p);
}
