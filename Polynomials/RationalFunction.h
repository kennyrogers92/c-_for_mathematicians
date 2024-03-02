/**
 * @file RationalFunction.h
 * @author kennyrogers (kenraposas92@gmail.com)
 * @brief Class Template of Rational Functions
 * @version 0.1
 * @date 2024-02-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef RATIONALFUNCTION_H
#define RATIONALFUNCTION_H

#include "Polynomial.h"

template <class K>
class RationalFunction {
    private:
        Polynomial<K> numerator;        // To hold the numerator
        Polynomial<K> denominator;      // To hold the denominator

        // Function to simplify the rational function
        void simplify() {
            Polynomial<K> D = gcd(numerator, denominator);
            numerator /= D;
            denominator /= D;
        }
        
    public:
        // Constructors;
        // Default Constructor: Zero polynomial
        RationalFunction<K>() {
            numerator = Polynomial<K>();
            denominator = Polynomial<K>(K(1));
        };

        // Constructs P(x)/1
        RationalFunction<K>(const Polynomial<K>& P) {
            numerator = P;
            denominator = Polynomial<K>(K(1));
        }

        // Constructs P(x)/Q(x) where P(x) and Q(x) are polynomials
        RationalFunction<K>(const Polynomial<K>& P, const Polynomial<K>& Q) {
            if (Q.isZero()) {
                std::cerr << "Warning: Denominator given is identically zero" << std::endl;
            }
            numerator = P;
            denominator = Q;
            simplify();
        }

        // Get and set methods
        Polynomial<K> getNum() const {
            return numerator;
        }

        Polynomial<K> getDenom() const {
            return denominator;
        }

        void setNum(const Polynomial<K>& P) {
            numerator = P;
        }

        void setDenom(const Polynomial<K>& Q) {
            denominator = Q;
        }

        // Arithmetic Operations (doesn't use coercion, strictly RationalFunction~RationalFunction)
        RationalFunction<K> operator+(const RationalFunction<K>& that) const {
            Polynomial<K> P, Q, R, S;
            P = Polynomial<K>(numerator);
            Q = Polynomial<K>(denominator);
            R = Polynomial<K>(that.numerator);
            S = Polynomial<K>(that.denominator);
            RationalFunction<K> ans;
            ans = RationalFunction<K>(P*S + R*Q, Q*S);
            return ans;
        }

        RationalFunction<K> operator+=(const RationalFunction<K> that) {
            *this = *this + that;
            return that;
        }

        RationalFunction<K> operator-() const {
            return RationalFunction<K>(-numerator, denominator);
        }

        RationalFunction<K> operator-(const RationalFunction& that) const {
            return *this + (-that);
        }

        RationalFunction<K> operator-=(const RationalFunction& that) const {
            *this = *this - that;
            return *this;
        }

        RationalFunction<K> operator*(const RationalFunction<K>& that) const {
            Polynomial<K> P, Q, R, S;
            P = numerator;
            Q = denominator;
            R = that.numerator;
            S = that.denominator;
            return RationalFunction<K>(P*R, Q*S);
        }
        
        RationalFunction<K> operator*=(const RationalFunction<K>& that) {
            *this = *this * that;
            return *this;
        }

        RationalFunction<K> inverse() const {
            RationalFunction<K> ans;
            if (numerator.isZero()) {
                std::cerr << "Warning: Zero rational function has no inverse." << std::endl;
                return ans;
            }
            Polynomial<K> temp = numerator;
            ans.setNum(denominator);
            ans.setDenom(temp);
            ans.simplify();
            return ans;
        }

        RationalFunction<K> operator/(const RationalFunction<K>& that) const {
            return *this * that.inverse();
        }

        RationalFunction<K> operator/=(const RationalFunction<K>& that) {
            *this = *this / that;
            return *this;
        }

        RationalFunction<K> pow(long k) const {
            return RationalFunction<K>(numerator.pow(k), denominator.pow(k));
        }

        // Returns the derivative of this rational function
        RationalFunction<K> derivative() const {
            RationalFunction<K> ans;
            ans.setNum(denominator*numerator.derivative() - numerator*denominator.derivative());
            ans.setDenom(denominator.pow(2));
            ans.simplify();
            return ans;
        }

        // Equality operator
        bool operator==(const RationalFunction<K>& that) const {
            return (numerator*that.denominator == denominator*that.numerator);
        }
};

template <class K>
std::ostream& operator<<(std::ostream& os, const RationalFunction<K>& R) {
    os << "(" << R.getNum() << ") / (" << R.getDenom() << ")";
    return os; 
}

#endif