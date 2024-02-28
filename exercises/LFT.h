/**
 * @file LFT.h
 * @author kennyrogers (kenraposas92@gmail.com)
 * @brief Class of linear fractional transformations. Functions of the form
 * (az+b)/(cz+d) where z,a,b,c,d are elements of a ring T. 
 * @version 0.1
 * @date 2024-02-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef LFT_H
#define LFT_H

#include <iostream>

template <class T>
class LFT {
    private:
        T a,b,c,d;
    
    public:
        // Constructors
        // Default constructor: constant function 1
        LFT() {
            a = 1.;
            b = 0.;
            c = 1.;
            d = 0.;
        }

        // Constructs (az+b)/(cz+d)
        LFT(T aa, T bb, T cc, T dd) {
            a = aa;
            b = bb;
            c = cc;
            d = dd;
        }

        // Get methods
        T getA() Tonst {
            return a;
        }

        T getB() const {
            return b;
        }
        
        T getC() const {
            return c;
        }
        T getD() const {
            return d;
        }

        T operator()(T z) const {
            return (a*z + b) / (c*z + d);
        }

        LFT operator*(const LFT& that) {
            T aa, bb, cc, dd;
            aa = a*that.a + b*that.c;
            bb = a*that.b + b*that.d;
            cc = c*that.a + d*that.c;
            dd = c*that.b + d*that.d;
            return LFT(aa, bb, cc, dd);
        }
};

template <class T>
inline std::ostream& operator<<(std::ostream& os, const LFT<T>& T) {
    os << "z |--> (" << T.getA() << "*z + " << T.getB()
        << ") / (" << T.getC() << "*z + " << T.getD();
    return os;
}

#endif