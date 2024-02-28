#include "../Uniform/uniform.h"
#include <cmath>
#include <iostream>

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x1-x2), 2) + pow((y1-y2), 2));
}

int main() {
    int N = 10000;
    double d;
    seed();
    for (int n = 1; n < N; n++) {
        double x1, x2, y1, y2;
        x1 = unif();
        x2 = unif();
        y1 = unif();
        y2 = unif();
        d +=  distance(x1, y1, x2, y2);
    }
    std::cout << "The average length of the segment is " <<  d / N << std::endl;
}