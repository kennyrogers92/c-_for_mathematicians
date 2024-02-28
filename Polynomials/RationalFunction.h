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

template <class T>
class RationalFunction {
    private:
        Polynomial<T> numerator;
        Polynomial<T> denominator;
    public:
        // Constructors;
        // Constructs P(x)/Q(x) where P(x) and Q(x) are polynomials
        RationalFunction(Polynomial<T>& P, Polynomial<T>& Q) {
            if (Q.isZero) {
                std::cerr << "Warning: Denominator given is identically zero" << std::endl;
            }
            numerator = P;
            denominator = Q;
        } 

        // Constructs P(x)/1
        RationalFunction(Polynomial<T>& P) {
            numerator = P;
            denominator = T(1);
        }

        // Arithmetic Operations
        RationalFunction operator+(const RationalFunction& that) const {
            
        }
};

#endif