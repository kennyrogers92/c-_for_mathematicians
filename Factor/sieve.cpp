#include "sieve.h"
#include <iostream>
#include <vector>
#include <chrono>

/**
 * Program to test the sieve procedures (table of primes
 * stored as array and vectors).
 */
int main() {
    const long N = 10000000;            // ten million
    const long TABLE_SIZE = 800000;     // prime number theorem overestimate (1.5n/logn)
    
    long* primesArray;
    primesArray = new long[TABLE_SIZE];
    auto tic = std::chrono::system_clock::now();
    long np = sieve(N, primesArray);
    auto toc = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(toc - tic);

    std::cout << "We use the sieve on " << N << " with primes stored in an array" << std::endl;
    std::cout << "We found " << np << " primes in " << elapsed.count() << " milliseconds" << std::endl;
    std::cout << "The first 10 primes we found are these: " << std::endl;
    for (long k = 0; k < 10; k++) std::cout << primesArray[k] << " ";
    std::cout << std::endl;

    std::cout << "The largest prime we found is " << primesArray[np-1] << std::endl;
    delete[] primesArray;
    std::cout << std::endl;

    std::vector<long> primesVector;
    tic = std::chrono::system_clock::now();
    np = sieve(N, primesVector);
    toc = std::chrono::system_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(toc - tic);

    std::cout << "Now we use the sieve on " << N << " with primes stored in a vector" << std::endl;
    std::cout << "We found " << np << " primes in " << elapsed.count() << " milliseconds" << std::endl;
    std::cout << "The first 10 primes we found are these: " << std::endl;
    for (long k = 0; k < 10; k++) std::cout << primesVector[k] << " ";
    std::cout << std::endl;

    std::cout << "The largest prime we found is " << primesVector[np-1] << std::endl;
    return 0;
}