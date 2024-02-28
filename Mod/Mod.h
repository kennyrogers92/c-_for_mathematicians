/**
 * @file Mod.h
 * @author kennyrogers92 (kenraposas92@gmail.com)
 * @brief Class for modular systems
 * @version 0.1
 * @date 2024-02-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef MOD_H
#define MOD_H

#include "../GCD/gcdx.h"
#include <iostream>

const long INITIAL_DEFAULT_MODULUS = 2;

class Mod {
    private:
        long mod;
        long val;
        static long default_modulus;
        void adjust_val() {
            val = val % mod;
            if (val < 0) val += mod;
        }

        public:
            // Constructors
            // Default Constructor: constructs 0 mod 2
            Mod() {
                mod = get_default_modulus();
                val = 0;
            }

            // Constructs x mod default_modulus
            Mod(long x) {
                mod = get_default_modulus();
                val = x;
                adjust_val();
            }

            // Constructs x mod m
            Mod(long x, long m) {
                if (m <= 0) {
                    val = 0;
                    mod = 0;
                }
                else {
                    mod = m;
                    val = x;
                    adjust_val();
                }
            }

            // Get and set methods
            long get_val() const { \
                return val;
            }

            void set_val(long x) {
                if (mod == 0) return;
                val = x;
                adjust_val();
            }

            long get_mod() const {
                return mod;
            }

            void set_mod(long m) {
                if (m <= 0) {
                    mod = 0;
                    val = 0;
                }
                else {
                    mod = m;
                    adjust_val();
                }
            }

            static void set_default_modulus(long m) {
                if (m <= 0) {
                    default_modulus = INITIAL_DEFAULT_MODULUS;
                }
                else {
                    default_modulus = m;
                }
            }

            static long get_default_modulus() {
                if (default_modulus <= 0) {
                    set_default_modulus(INITIAL_DEFAULT_MODULUS);
                }
                return default_modulus;
            }

            // Checks if current modulus is valid
            bool is_invalid() const {
                return mod == 0;
            }

            // Equality operator
            bool operator==(const Mod& that) const {
                return ( (val == that.val) && (mod == that.mod) );
            }

            bool operator==(long that) const {
                return (*this) == Mod(that, mod);
            }

            bool operator!=(const Mod& that) const {
                return !((*this) == that);
            }
            
            bool operator!=(long that) const {
                return !((*this) == Mod(that, mod));
            }

            // Comparator: compares modulus then their values
            bool operator<(const Mod& that) const {
                if (mod < that.mod) return true;
                if (mod > that.mod) return false;
                if (val < that.val) return true;
                return false;
            }

            // Arithmetic Operations
            Mod add(Mod that) const {
                if (is_invalid() || that.is_invalid()) return Mod(0, 0);
                if (mod != that.mod) return Mod(0, 0);
                return Mod(val + that.val, mod);
            }

            Mod operator+(const Mod& x) const {
                return add(x);
            }

            Mod operator+(long x) const {
                return add(Mod(x, mod));
            }

            Mod operator+=(const Mod& x) {
                *this = add(x);
                return *this;
            }

            Mod operator+=(long x) {
                *this = add(Mod(x, mod));
                return *this;
            }

            Mod operator-() const {
                return Mod(-val, mod);
            }

            Mod operator-(const Mod& x) const {
                return (*this) + (-x);
            }

            Mod operator-(long x) const {
                return (*this) + (-x);
            }

            Mod operator-=(const Mod& x) {
                *this = add(-x);
                return *this;
            }

            Mod operator-=(long x) {
                *this = *this + (-x);
                return *this;
            }

            Mod multiply(Mod that) const {
                if (is_invalid() || that.is_invalid()) return Mod(0, 0);
                if (mod != that.mod) return Mod(0, 0);
                return Mod(val * that.val, mod);
            }

            Mod operator*(const Mod& x) const {
                return multiply(x);
            }

            Mod operator*(long x) const {
                return multiply(Mod(x, mod));
            }

            Mod operator*=(const Mod& x) {
                *this = multiply(x);
                return *this;
            }

            Mod operator*=(long x) {
                *this = multiply(Mod(x, val));
                return *this;
            }

            Mod inverse() const {
                long d, a, b;
                if (is_invalid()) return Mod(0, 0);

                d = gcd(val, mod, a, b);

                if (d > 1) return Mod(0, 0);
                return Mod(a, mod);
            }

            Mod operator/(const Mod& x) const {
                return multiply(x.inverse());
            }

            Mod operator/(long x) const {
                return multiply(Mod(x, mod).inverse());
            }

            Mod operator/=(const Mod& x) {
                *this = multiply(x.inverse());
                return *this;
            }

            Mod operator/=(long x) {
                *this = multiply(Mod(x, mod).inverse());
                return *this;
            }

            Mod pow(long k) const {
                // corner case
                if (is_invalid()) return Mod(0, 0);

                // negative exponent
                if (k < 0) return (inverse()).pow(-k);

                // zero exponent
                if (k == 0) return Mod(1, mod);

                // exponent equal to 1
                if (k == 1) return *this;

                // even exponent
                if (k % 2 == 0) {
                    Mod temp = pow(k/2);
                    return temp*temp;
                }

                // odd exponent
                Mod temp = pow((k-1)/2);
                return temp*temp*(*this);
            }
};

std::ostream& operator<<(std::ostream& os, const Mod& M) {
    if (!M.is_invalid()) {
        os << "Mod(" << M.get_val() << ", " << M.get_mod() << ")"; 
    }
    else {
        os << "INVALID";
    }
    return os;
}

inline bool operator==(long x, const Mod& y) {
    return (y == x);
}

inline bool operator!=(long x, const Mod& y) {
    return (y != x);
}

inline Mod operator+(long x, Mod y) {
    return y + x;
}

inline Mod operator-(long x, Mod y) {
    return (-y) + x;
}

inline Mod operator*(long x, Mod y) {
    return y*x;
}

inline Mod operator/(long x, Mod y) {
    return y.inverse() * x;
}

long Mod::default_modulus = INITIAL_DEFAULT_MODULUS;

/**
 * @brief Chinese Remainder Theorem. Solves for solution/s
 * of systems of two linear equations
 * x = a mod n
 * x = b mod m
 * @param x Mod (a, n)
 * @param y Mod (b, m)
 * @return Mod solution to the above system
 */
Mod crt(const Mod& x, const Mod& y) {
    Mod xx = x / y.get_mod();
    Mod yy = y / x.get_mod();
    long val = x.get_val()*xx.get_val()*y.get_mod() + y.get_val()*yy.get_val()*x.get_mod();
    long mod = x.get_mod()*y.get_mod();
    return Mod(val, mod);
}

#endif