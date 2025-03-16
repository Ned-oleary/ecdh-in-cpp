#include<iostream>
#include "../include/key_exchange.h"


int main() {

    // test with an ultra small prime, simple curve

    int64_t p = 23;
    int64_t a = 1;
    int64_t n = 19;

    EllipticCurvePoint G(9, 5);

    // Entity A
    int64_t d_A = generate_private_key(n);
    EllipticCurvePoint P_A = compute_public_key(d_A, G, a, p);

    // Entity B
    int64_t d_B = generate_private_key(n);
    EllipticCurvePoint P_B = compute_public_key(d_B, G, a, p);

    // Shared secrets (really singular, but illustrative to show both sides)
    EllipticCurvePoint S_A = compute_shared_secret(d_A, P_B, a, p);
    EllipticCurvePoint S_B = compute_shared_secret(d_B, P_A, a, p);

    std::cout << "Entity A private key: " << d_A << "\n";
    std::cout << "Entity A public key: (" << P_A.x << ", " << P_A.y << ")\n";
    
    std::cout << "Entity B privat key: " << d_B << "\n";
    std::cout << "Entity B public key: (" << P_B.x << ", " << P_B.y << ")\n";

    std::cout << "Shared Secret (Entity A): (" << S_A.x << ", " << S_A.y << ")\n";
    std::cout << "Shared Secret (Entity B): (" << S_B.x << ", " << S_B.y << ")\n";

    return 0;

}