#include "gcd.h"
#include <iostream>
#include <chrono>

/**
 * Simple main program to test and compare the runtime of
 * recursive and iterative gcd.
 */
int main() {
    long a = 897987637,
         b = 123456789;

    std::cout << "Computing for the gcd of " << a << " and " << b << std::endl;

    auto tic = std::chrono::high_resolution_clock::now();
    gcd(a, b, Iterative);
    auto toc = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(toc - tic);
    std::cout << "Seconds passed for computing gcd iteratively is "
        << elapsed.count() << " nanoseconds" << std::endl;

    tic = std::chrono::high_resolution_clock::now();
    gcd(a, b, Recursive);
    toc = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(toc - tic);
    std::cout << "Seconds passed for computing gcd recursively is "
        << elapsed.count() << " nanoseconds" << std::endl;
    return 0;
}