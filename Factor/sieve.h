#ifndef SIEVE_H
#define SIEVE_H

#include <vector>

/**
 * @brief The Seive of Erasthothenes: Generate a table of primes.
 * 
 * @param n upper limit on the primes (i.e., we find all primes
 * less than equal to n).
 * @param primes array to hold the table of primes.
 * @return the number of primes we found.
 */
long sieve(long n, long* primes) {
    // No primes less than 2
    if (n < 2) return 0;

    // array to hold the marks
    char* theSieve;
    theSieve = new char[n+1];

    // Names of marks in theSieve
    const char blank = 0;
    const char marked = 1;

    // Initialize theSieve with blank marks
    for (long k = 2; k <= n; k++) theSieve[k] = blank;

    long idx = 0;

    for (long k=2; k <= n; k++) {
        // found an unmarked elt k, mark and then record k in the primes arr
        if (theSieve[k] == blank) {
            theSieve[k] = marked;
            primes[idx] = k;
            idx++;
        }
        // Mark off all multiples of k
        for (long d=2*k; d <= n; d+=k) theSieve[d] = marked;
    }
    delete[] theSieve;
    return idx;
}

/**
 * @brief The Seive of Erasthenes: Generate a table of primes.
 * 
 * @param n upper limit on the primes (i.e., we find all primes
 * less than equal to n).
 * @param primes vector to hold the table of primes.
 * @return the number of primes we found.
 */
long sieve(long n, std::vector<long>& primes) {
    primes.clear(); // erase the sieve

    if (n < 2) return 0;

    /*
     * Make a table of bool values where true for prime and
     * false for composite. Initialize the table to all true.
     */
    std::vector<bool> theSieve;
    theSieve.resize(n+1);
    for (long k = 2; k <= n; k++) theSieve[k] = true;

    long idx = 0;
    for (long k = 2; k <= n; k++) {
        if (theSieve[k]) {
            primes.resize(idx + 1);
            primes[idx] = k;
            idx++;   
        }
        for (long d = 2*k; d <= n; d += k) theSieve[d] = false;
    }
    return primes.size();
}

#endif