#include <iostream>
#include <iomanip>
#include <cmath>

float forwardBasel(int n) {
    float sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += 1.0/(float(i)*float(i));
    }
    return sum;
}

float backwardBasel(int n) {
    float sum = 0;
    for (int i = n; i >= 1; i--) {
        sum += 1.0/(float(i)*float(i));
    }
    return sum;
}

int main() {
    int n = 1000000;
    std::cout << "Finite Basel Problem: Sum of inverse of squares up to " << n << " terms\n";
    std::cout << "The forward Basel sum is \t" << std::setprecision(15) << forwardBasel(n) << std::endl;
    std::cout << "The backward Basel sum is \t" << std::setprecision(15) << backwardBasel(n) << std::endl;
    std::cout << "The true value of Basel sum is \t" << std::setprecision(15) << M_PI*M_PI/6 << std::endl;
    return 0;
}