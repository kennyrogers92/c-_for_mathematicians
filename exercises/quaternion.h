/**
 * @file quaternion.h
 * @author kennyrogers92 (kenraposas92@gmail.com)
 * @brief Class of Quaternions represented
 *  by a + bi + cj + dk where a, b, c, d are real numbers
 * Round off errors arise in the division of quaternions
 * @version 0.1
 * @date 2024-02-21
 * 
 * @copyright Copyright (c) 2024
 */
#ifndef QUATERNION_H
#define QUATERNION_H

#include <iostream>

class quaternion {
    private:
        double a, b, c, d;
    public:
        // Constructors
        // Default Constructor: construct the zero
        quaternion() {
            a = b = c = d = 0;
        }

        // Construct aa + bbi + ccj + ddk
        quaternion(double aa, double bb, double cc, double dd) {
            a = aa;
            b = bb;
            c = cc;
            d = dd;
        }

        // Get and set methods
        double getA() const {
            return a;
        }

        void setA(double a) {
            a = a;
        }

        double getB() const {
            return b;
        }

        void setB(double b) {
            b = b;
        }

        double getC() const {
            return c;
        }

        void setC(double c) {
            c = c;
        }

        double getD() const {
            return d;
        }

        void setD(double d) {
            d = d;
        }

        // Arithmetic operations
        quaternion operator+(const quaternion& that) const {
            return quaternion(a+that.a, b+that.b, c+that.c, d+that.d);
        }

        quaternion operator+=(const quaternion& that) {
            *this = *this + that;
            return *this;
        }

        quaternion operator-() const {
            return quaternion(-a, -b, -c, -d);
        }
        quaternion operator-(const quaternion& that) const {
            return (*this) + (-that);
        }

        quaternion operator-=(const quaternion& that) {
            *this = *this - that;
            return *this;
        }

        quaternion operator*(const quaternion& that) const {
            return quaternion(a*that.a - b*that.b - c*that.c - d*that.d, a*that.b + b*that.a + c*that.d - d*that.c,
                a*that.c - b*that.d + c*that.a + d*that.b, a*that.d + b*that.c - c*that.b + d*that.a);
        }

        quaternion operator*=(const quaternion& that) {
            *this = *this*that;
            return *this;
        }

        quaternion operator*(double x) const {
            return quaternion(a*x, b*x, c*x, d*x);
        }

        quaternion operator*=(double x) {
            *this = *this*x;
            return *this;
        }

        quaternion inverse() const {
            // Check if that is zero quaternion
            if (isZero()) {
                std::cerr << "Warning: this quaternion is zero" << std::endl;
                return quaternion();
            }
            double r = a*a + b*b + c*c + d*d;
            return quaternion(a, -b, -c, -d)*(1./r);

        }

        quaternion operator/(const quaternion& that) const {
            // Check if that is zero quaternion
            if (that.isZero()) {
                std::cerr << "Warning: Divisor is zero" << std::endl;
                return quaternion();
            }
            return *this * that.inverse();
        }

        quaternion operator/=(const quaternion& that) {
            *this = *this/that;
            return *this;
        }

        quaternion operator/(double x) const {
            if (x == 0.) {
                std::cerr << "Warning: Divisor is zero" << std::endl;
                return quaternion();
            }
            return quaternion(a/x, b/x, c/x, d/x);
        }

        quaternion operator/=(double x) {
            if (x == 0.) {
                std::cerr << "Warning: Divisor is zero" << std::endl;
                return quaternion();
            }
            *this = *this/x;
            return *this;
        }

        // Equality operator
        bool operator==(const quaternion& that) {
            if (a != that.a || b != that.b || c != that.c || d != that.d) {
                return false;
            }
            return true;
        }

        bool operator!=(const quaternion& that) {
            return !(*this == that);
        }

        bool isZero() const {
            if (a != 0. || b != 0. || c != 0 || d != 0) return false;
            return true;  
        }
};

std::ostream& operator <<(std::ostream& os, const quaternion& Q) {
    os << std::noshowpos << "(" << Q.getA() << ") + (" << Q.getB() << ")i + ("
        << Q.getC() << ")j + (" << Q.getD() << ")k";
    return os;         
}

quaternion operator*(double x, const quaternion& Q) {
    return Q*x;
}

quaternion operator/(double x, const quaternion& Q) {
    if (Q.isZero()) {
        std::cerr << "Warning: Divisor is zero" << std::endl;
    }
    return quaternion(x,0,0,0)/Q;
}

#endif