#ifndef GCD_H
#define GCD_H

/**
 * @brief Calculate the greatest common divisor of two integers.
 * Note: gcd(0, 0) will return 0 and print an error message
 * @param a the first integer
 * @param b the second integer
 * @return the greatest common divisor of a and b
 */

enum GCDVersion {Iterative, Recursive};

long gcd(long& a, long& b, GCDVersion version);

long gcdIterative(long a, long b);

long gcdRecursive(long a, long b);

#endif
