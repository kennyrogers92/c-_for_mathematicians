#include "gcdx.h"
#include <iostream>

/**
 * Simple main program to test extended gcd procedure 
 */
int main() {
    long a, b, x, y;

    std::cout << "Enter the first number -->";
    std::cin >> a;
    std::cout << "Enter the second number -->";
    std::cin >> b;

    long d = gcd(a, b, x, y);
    std::cout << "The gcd of " << a << " and " << b << " is "
        << d << std::endl;
    std::cout << "Further, " << d << " = " << a << "*" << x << " + " << b << "*" << y << std::endl;
    return 0;
}