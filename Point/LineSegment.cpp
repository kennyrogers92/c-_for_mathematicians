#include "LineSegment.h"

/**
 * A program to test the LineSegment class. The same issue with
 * equality operator in Line can also arise.
 */

int main() {
    Point A(1, 1);
    Point B(-1, 1);   
    LineSegment L;
    LineSegment M(A, B);
    LineSegment N(1., 1., -1., 1.);

    std::cout << "The lines L, M, and N are" << L << ",\n\t"
        << M << " and " << N << " respectively" << std::endl;
    std::cout << "The length of M is " << M.length() << std::endl;
    std::cout << "The midpoint of N is " << N.midpoint() << std::endl;
    std::cout << "Is M = N?";
    if (M==N) {
        std::cout << " True" << std::endl;
    }
    else {
        std::cout << " False" << std::endl;
    }
    return 0;
}