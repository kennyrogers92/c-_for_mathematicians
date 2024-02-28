/**
 * @file Complexx.h
 * @author kennyrogers (kenraposas92@gmail.com)
 * @brief Class of extended complex numbers
 * @version 0.1
 * @date 2024-02-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef COMPLEXX_H
#define COMPLEXX_H

#include <complex>

typedef double R;
typedef std::complex<R> C;

class Complexx : public C {
    private:
        bool infinite;
        bool invalid;
    public:
        // Constructors
        Complexx(C z) : C(z) {
            infinite = false;
            invalid = false;
        }
        
        Complexx(R a, R b) : C(a, b) {
            infinite = false;
            invalid = false;
        }

        // Check if zero, infinite or invalid
        bool isZero() const {
            return !invalid && !infinite && C(*this) == C(0);
        }
        
        bool isInfinite() const {
            return !invalid && infinite;
        } 

        bool isInvalid() const {
            return invalid;
        }

        // Equality operator
        bool operator==(const Complexx& that) const {
            if (invalid || that.invalid) return false;
            if(infinite && that.infinite) return true;
            return C(*this) == C(that);
        }

        bool operator!=(const Complexx& that) const {
            if (invalid || that.invalid) return false;
            return !(*this == that);
        }

        // Arithmetic Operations
        Complexx operator+(const Complexx& that) const {
            // Cast sum to complex<double>
            Complexx ans(C(*this) + C(that));
            // If both are invalid, set sum as invalid
            if (invalid || that.invalid) {
                ans.invalid = true;
                return ans;
            }
            // If summands are infinite, set sum as invalid
            if (infinite && that.infinite) {
                ans.invalid = true;
                return ans;
            }
            // If exactly one summand is infinite, set sum as infinite
            if (infinite || that.infinite) {
                ans.infinite = true;
                return ans;
            }
            // Otherwise, both sum are finite
            return ans;
        }

        Complexx operator-() const {
            // Cast this to complex<double>
            Complexx ans(-C(*this));
            // If this is invalid, set ans to invalid
            if (invalid) {
                ans.invalid = true;
                return ans;
            }
            // If this is infinite, set ans to infinite
            if (infinite) {
                ans.infinite = true;
                return ans;
            }
            // Otherwise, this is finite
            return ans;
        }

        Complexx operator-(const Complexx& that) const {
            return (*this) + (-that);
        }

        Complexx operator*(const Complexx& that) const {
            // Cast product to complex<double>
            Complexx ans(C(*this) * C(that));
            // If one factor is invalid, set ans to invalid
            if (invalid || that.invalid) {
                ans.invalid = true;
                return ans;
            }
            // If one is infinite and the other is zero, set ans as invalid
            if (infinite && that.isZero() || isZero() && that.isZero()) {
                ans.invalid = true;
                return ans;
            }
            // If either factor is infinite and the other is nonzero, set ans as infinite
            if (infinite || that.isInfinite()) {
                ans.infinite = true;
                return ans;
            }
            // Otherwise, both factors are finite
            return ans;
        }
        Complexx operator/(const Complexx& that) const {
            // Cast quotient to complex<double>
            Complexx ans(C(*this) / C(that));
            // If dividend/divisor is invalid, set ans to invalid
            if (invalid || that.invalid) {
                ans.invalid = true;
                return ans;
            }
            // If both are zero, set ans as invalid
            if (isZero() && that.isZero()) {
                ans.invalid = true;
                return ans;
            }
            // If both are infinite, set ans as invalid
            if (infinite && that.infinite) {
                ans.invalid = true;
                return ans;
            }
            // If dividend is infinite and the divisor is finite, set ans as infinite
            if (infinite) {
                ans.infinite = true;
                return ans;
            }
            // If divisor is infinite, set ans as zero
            if (that.infinite) {
                ans = Complexx(0., 0.);
                return ans;
            }
            // If divisor is zero, set ans as infinite
            if (that.isZero()) {
                ans.infinite = true;
                return ans;
            }
            // Otherwise both are finite
            return ans;
        }
};

std::ostream& operator<<(std::ostream& os, const Complexx& z) {
    if (z.isInvalid()) {
        os << "INVALID";
        return os;
    }
    if (z.isInfinite()) {
        os << "Infinity";
        return os;
    }
    os << C(z);
    return os;
}

#endif