#include "totient.h"
#include "factor.h"
#include "sieve.h"
#include <iostream>
#include <string>

/**
 * Program to test the faster version of Euler's totient on
 * the integers from 1 to 1000
 */
int main() {
    for (int k = 1; k < 1001; k++) {
        std::cout << k << "\t" << totient(k) << std::endl;
    }
    std::cout << std::endl;
    const int N = 100;
    long primes[10*N];
    sieve(10*N, primes);

    std::cout << std::string(14, '-') << std::endl;
    std::cout << "n\tphi(n)" << std::endl;
    std::cout << std::string(14, '-') << std::endl;
    for (long k = 1; k <= N; k++) {
        std::cout << k << "\t" << totient(k, primes) << std::endl;
    }
    std::cout << std::string(14, '-') << std::endl;
    return 0;
}