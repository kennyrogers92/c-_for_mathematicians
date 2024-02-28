/**
 * @file Interval.h
 * @author kennyrogers92 (kenraposas92@gmail.com)
 * @brief Interval class for 1D closed intervals of real numbers
 * @version 0.1
 * @date 2024-02-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef INTERVAL_H
#define INTERVAL_H

#include<iostream>

class Interval {
    private:
        // endpoints of a and b
        double a, b;
    public:
        // Constructors
        // Default Constructor construct the interval with endpoints 0 and 1
        Interval() {
            a = 0.;
            b = 1.;
        }
        
        Interval(double c, double d) {
            if (c < d) {
                a = c;
                b = d;
            }
            else {
                a = d;
                b = c;

            }
        }

        // Get methods
        double getA() const {
            return a;
        }
        
        double getB() const {
            return b;
        }

        // Equality operator
        bool operator==(const Interval& that) const {
            return ( (a == that.a) && (b == that.b) );
        }

        bool operator!=(const Interval& that) const {
            return ( *this == that);
        }

        bool operator<(const Interval& that) const {
            if (a < that.a) return true;
            if (a > that.a) return false;
            return b < that.b;
        }
};


std::ostream& operator<<(std::ostream& os, const Interval& I) {
    os << "[" << I.getA() << ", " << I.getB() << "]";
    return os;
}

#endif