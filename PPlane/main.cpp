#include <iostream>
#include "Projective.h"


int main() {
    seed();
    PPoint P;

    P.randomize();
    std::cout << "The random point P is " << P << std::endl;

    PLine L, M;

    L = P.rand_line();
    M = P.rand_line();

    std::cout << "Two lines through P are L = " << L << std::endl
        << "\tand M" << M << std::endl;
    
    std::cout << "Is P on L? " << P.is_on(L) << std::endl;
    std::cout << "Does M have P? " << M.has(P) << std::endl;

    PPoint Q;
    Q = L*M;

    std::cout << "The point of intersection of L and M is Q = " << Q << std::endl;

    std::cout << "Is Q on L? " << Q.is_on(L) << std::endl;
    std::cout << "Does M have Q? " << M.has(Q) << std::endl;

    if (P == Q) {
        std::cout << "P and Q are equal" << std::endl;
    }
    else {
        std::cout << "P and Q are NOT equal" << std::endl;
    }

    return 0;
}