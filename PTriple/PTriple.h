/**
 * @file PTriple.h
 * @author kennyrogers92 (kenraposas92@gmail.com)
 * @brief A PTRIPLE represents a reduced Pythagorean triple. That is, a
 * a sequence of three nonnegative integers (a, b, c) in nondecreasing order
 * for which a^2 + b^2 = c^2 and (a, b, c) are relatively prime. The
 * relatively prime requirement means that we only deal with primitive 
 * Pythagorean triples. We allow (0, 0, 0).
 * @version 0.1
 * @date 2024-02-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef PTRIPLE_H
#define PTRIPLE_H

#include <iostream>
#include "../GCD/gcd.h"

class PTriple {
    private:
        // Shorter leg of the triple
        long a;
        // Longer leg of the triple
        long b;
        // Hypotenuse
        long c;

        /**
         * @brief This private method makes sure the triple elements are
         * nonnegative, in nondecreasing order, and relatively prime.
         */
        void reduce() {
            // Corner case (a=b=c=0)
            if ( (a == 0) && (b == 0) && (c == 0) ) return;

            // Make sure a, b are nonnegative (c must be)
            if (a < 0) a = -a;
            if (b < 0) a = -b;

            // Check a <= b;
            if (a > b) {
                long temp = a;
                a = b; 
                b = temp;
            }

            // Make sure a, b, c are relatively prime
            long d = gcd(a, b, Iterative);
            a /= d;
            b /= d;
            c /= d;
        }
    
    public:
        // Constructors
        // Default Constructor. Makes the triple (0,0,0)
        PTriple() {
            a = b = c = 0;
        }

        /**
         * Construct from a pair of integers. Given integers m and n, 
         * we make a Pythagorean triple by taking the legs to be 2mn, and
         * m^2-n^2 and the hypotenuse to be m^2+n^2. We then make sure the
         * three numbers are nonnegative, in nondecreasing order, and then
         * divide out by their gcd.
         */
        PTriple(long m, long n) {
            a = 2*m*n;
            b = m*m - n*n;
            c = m*m + n*n;

            reduce();
        }

        // Get methods
        long getA() const {
            return a;
        }
        long getB() const {
            return b;
        }
        long getC() const {
            return c;
        }

        /**
         * @brief Check if this PTriple is less than another. The ordering is
         * lexicographic starting from c.
         * @param that Another PTriple
         * @return true if this PTriple is lexicographically less than that.
         */
        bool operator<(const PTriple& that) const {
            if (c < that.c) return true;
            if (c > that.c) return false;
            if (b < that.b) return true;
            return false;
        }

        /**
         * @brief Check if this PTriple is equal to another.
         */
        bool operator==(const PTriple& that) const {
            return ( (a == that.a) && (b == that.b) && (c == that.c) );
        }

        /**
         * @brief Check if this PTriple is not equal to another
         */
        bool operator!=(const PTriple& that) const {
            return !( (*this) == that );
        }
};

// Send a PTriple to an output stream
std::ostream& operator<<(std::ostream& os, const PTriple& PT) {
    os << "(" << PT.getA() << ", " << PT.getB() << ", " << PT.getC() << ")";
    return os;
}

#endif