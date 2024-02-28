#include "Line.h"

/**
 * A program to test the class Line. Problems with equality operators
 * arise from roundoff errors due to division. For a solution to this problem,
 * replace exact equality test with |x-y|<eps where eps is built into the code
 * or is set by the user. See PPlane folder. 
 */

int main() {
    Point X(5, 3);
    Point Y(-2, 8);
    Line L(X, Y);
    Line N(1, 1, 1);
    std::cout << "X = " << X << std::endl;
    std::cout << "Y = " << Y << std::endl;
    std::cout << "The line L through X and Y is " << L << std::endl;

    Point Q;
    Q = L.find_Point();
    std::cout << "Q = " << Q << " is a point on L" << std::endl;
    Line M(X, Q);
    std::cout << "The line M through X and Q is " << M << std::endl;
    std::cout << "Are lines L and M the same?\t" << (L==M) << std::endl;
    std::cout << "Is Y incident with M?\t" << M.incident(Y) << std::endl;
    std::cout << "Distance from Y to M is zero?\t" << (dist(Y, M) == 0) << std::endl;
    std::cout << intersect(L, N, X) << X << std::endl;
    return 0;
}