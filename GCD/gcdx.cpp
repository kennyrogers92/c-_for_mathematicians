#include "gcdx.h"
#include <iostream>
using  namespace std;

/**
 * @brief Calculate the greatest common divisor of two integers.
 * Extended recursive version of gcd that returns x, y
 * where ax + by = gcd(a, b)
 * Note: gcd(0, 0) will return 0 and print an error message
 * @param a the first integer
 * @param b the second integer
 * @return the greatest common divisor of a and b
 */
long gcd(long a, long b, long &x, long &y) {
    long d;   // final gcd

    // if b = 0, gcd(a, b) = |a|, x=1 or -1, y arbitrary
    if (b==0) {
        if (a<0) {
            d = -a;
            x = -1;
            y = 0;
        }
        else {
            d = a;
            x = 1;
            y = 0;
        }
        return d;
    }

    // If b is negative, find gcd(a, -b)
    if (b<0) {
        d = gcd(a,-b,x,y);
        y = -y;
        return d;
    }

    if (a<0) {
        d = gcd(-a,b,x,y);
        x = -x;
        return d;
    }

    // Recursive step
    long aa = b;
    long bb = a%b;
    long qq = a/b;
    long xx, yy;

    d = gcd(aa,bb,xx,yy);

    x = yy;
    y = xx - qq*yy;

    return d;
}