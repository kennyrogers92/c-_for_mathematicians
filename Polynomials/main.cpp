#include "Polynomial.h"
#include "RationalFunction.h"

/**
 * Main program to test class of polynomials and rational functions
 */
int main() {
    Polynomial<double> P;
    Polynomial<double> Q(1);
    Polynomial<double> R(1,1,1);
    double coef [4];
    for (int i = 0; i < 4; i++) {
        coef[i] = 4-i;
    }
    Polynomial<double> S(4, coef);

    std::cout << "Testing the Polynomial class" << std::endl;

    std::cout << "P = " << P << std::endl;
    std::cout << "Q = " << Q << std::endl;
    std::cout << "R = " << R << std::endl;
    std::cout << "S = " << S << std::endl;

    std::cout << "deg(P) = " << P.deg() << std::endl;
    std::cout << "deg(S) = " << S.deg() << std::endl;

    std::cout << "The leading coefficient of S is " << S.get(S.deg()) << std::endl;
    std::cout << "Change the coefficient of X^4 of P to 1" << std::endl;
    P.set(4, 1);
    std::cout << "Now P is " << P << std::endl;
    Q.clear();
    std::cout << "Now Q is identically zero: Q = " << Q << std::endl;

    std::cout << "Is P zero? " << P.isZero() << std::endl;
    
    R.shift();
    std::cout << "Multiply R by x: now R is " << R << std::endl;

    Polynomial<double> T;
    T = S(R); 
    std::cout << "Define T as the composition S with R.\n T is " << T << std::endl;  
    std::cout << "What is the value of T(1)? " << T(1) << std::endl;
    std::cout << "Is it equal to S(R(1))? " << (T(1) == S(R(1))) << std::endl;

    std::cout << "Are P and Q equal? " <<  (P == Q) << std::endl;
    
    Q.set(0, 1);
    Q.set(1, 2);
    Q.set(2, 3);
    
    std::cout << "S is " << S << std::endl;
    std::cout << "Q is now " << Q << std::endl;
    std::cout << "S/Q = " << S / Q << std::endl;
    std::cout << "S%Q = " << S % Q << std::endl;
    
    std::cout << "Testing the RationalFunction class" << std::endl;
    std::cout << "The zero rational function " << RationalFunction<double>() << std::endl;
    std::cout << "The function P(X)/1 = " << RationalFunction<double>(P) << std::endl;
    std::cout << "The function Q(X)/R(X) = " << RationalFunction<double>(Q, R) << std::endl;

    std::cout << "Define U(X) = Q(X)/R(X) and "
        << "V(X) = S(X)/P(X)" << std::endl;

    RationalFunction<double> U (Q, R), V (S, P);

    std::cout << "U(X) = " << U << std::endl;
    std::cout << "V(X) = " << V << std::endl;

    std::cout << "(U + V)(X) = " << U + V << std::endl;
    std::cout << "(U - V)(X) = " << U - V << std::endl;
    std::cout << "(U * V)(X) = " << U * V << std::endl;
    std::cout << "(U / V)(X) = " << U / V << std::endl;
    std::cout << "U^2 = " << U.pow(2) << std::endl;
    std::cout << "Dx(U(X)) = " << U.derivative() << std::endl;
}