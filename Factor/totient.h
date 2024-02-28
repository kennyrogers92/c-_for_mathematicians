#ifndef TOTIENT_H
#define TOTIENT_H

#include "factor.h"

/**
 * Euler's totient function phi(n) defined as the number of positive 
 * integers not exceeding n that are relatively prime to n.
 * @param n the number whose totient we seek
 * @return the number of elements in {1,2,...,n} that are relatively
 * prime to n.
 */
long totient(long n) {
    // handle special cases
    if (n <= 0) return 0;
    if (n == 1) return 1;

    // factor n
    long flist[100];
    long nfactors = factor(n, flist);

    long ans = 1;

    for (long k = 0; k < nfactors; k++) {
        if (k < nfactors - 1) {
            if (flist[k] == flist[k+1]) {
                ans *= flist[k];
            }
            else {
                ans *= flist[k] - 1;
            }
        }
        else {
            ans *= flist[k] - 1;
        }
    }
    return ans;
}

/**
 * @brief Euler's totient function phi(n) defined as the number of positive 
 * integers not exceeding n that are relatively prime to n.
 * @param n the number whose totient we seek
 * @param primes 
 * @return the number of elements in {1,2,...,n} that are relatively
 * prime to n.
 */
long totient(long n, const long* primes) {
    if (n <= 0) return 0;

    long ans = n;
    for (long k = 0; primes[k] <= n; k++) {
        if (n % primes[k] == 0) {
            ans /= primes[k];
            ans *= primes[k] - 1;
        }
    }
    return ans;
}

#endif