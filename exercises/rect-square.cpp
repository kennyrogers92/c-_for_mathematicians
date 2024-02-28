#include "Square.h"

#define SHOW(a) std::cout << #a << ": " << (a) << std::endl

/**
 * Program to test Rectangle and Square classes
 */
int main() {
    Rectangle R;
    Rectangle S(2, 3);
    Square Q;

    SHOW(R);
    SHOW(S);
    std::cout << "Is R a square? ";
    if (R.isSquare()) {
        std::cout << "True" << std::endl;
    }
    else {
        std::cout << "False" << std::endl;
    }
    std::cout << "Is S a square? ";
    if (S.isSquare()) {
        std::cout << "True" << std::endl;
    }
    else {
        std::cout << "False" << std::endl;
    }

    SHOW(Q);
    std::cout << "Is R == Q? ";
    if (R == Q) {
        std::cout << "True" << std::endl;
    }
    else {
        std::cout << "False" << std::endl;
    }
    std::cout << "Is Q == R? ";
    if (Q == R) {
        std::cout << "True" << std::endl;
    }
    else {
        std::cout << "False" << std::endl;
    }

    return 0;
}