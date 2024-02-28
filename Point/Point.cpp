#include "Point.h"
#include <cmath>

/**
 * A main to test the Point class. 
 */

int main() {
    Point X;
    Point Y(3,4);

    std::cout << "The point X is " << X << " and the Point Y "
        << Y << std::endl;
    std::cout << "Point Y in polar coordinates is ("
        << Y.getR() << ", " << Y.getA() << ")" << std::endl;

    std::cout << "The distance between these points is "
        << dist(X, Y) << std::endl;
    std::cout << "The midpoint between these points is "
        << midpoint(X, Y) << std::endl;

    Y.rotate(M_PI/2);
    std::cout << "After 90-degree rotation, Y = " << Y << std::endl;

    Y.setR(100);
    std::cout << "After rescaling, Y = " << Y << std::endl;

    Y.setA(M_PI/4);
    std::cout << "After setting Y's angle to 45 degrees, Y = " << Y << std::endl;

    Point Z;
    Z = Y;
    std::cout << "After setting Z = Y, we find Z = " << Z << std::endl;

    X = Point(5, 3);
    Y = Point(5, -3);

    std::cout << "Now point X is " << X << " and point Y is " << Y << std::endl;
    if (X == Y) {
        std::cout << "They are equal." << std::endl;
    }
    if (X != Y) {
        std::cout << "They are not equal." << std::endl;
    }

    std::cout << "Y < X is ";
    if (Y < X) {
        std::cout << "true" << std::endl;
    }
    else {
        std::cout << "false" << std::endl;
    }

    Point P(3,5);
    (P.translate(1,2)).translate(10,10);
    std::cout << "(3,5) + (1,2) + (10,10) = " << P << std::endl;
    return 0;
}
