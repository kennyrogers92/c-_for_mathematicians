#include "../Uniform/uniform.h"
#include <iostream>
#include <cmath>
#include <chrono>
#include <utility>

enum Method {Systematic, Brute};

void point_on_circle(double&x , double& y, Method method) {
    seed();
    switch (method) {
    case Systematic:
    {
        double theta = unif()*2*M_PI;
        x = cos(theta);
        y = sin(theta);
        break;
    }
    case Brute:
    {
        double d;
        while (true) {
            x = unif();
            y = unif();
            d = x*x + y*y;
            if (d <= 1) break; 
        }
        x /= d;
        y /= d;
        break;
    }
    }
}

int main() {
    int N = 100000000;  // million 
    double x, y;

    auto tic = std::chrono::system_clock::now();
    for (int n = 0; n < N; n++) {
        point_on_circle(x, y, Systematic);
    }
    auto toc = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(toc - tic);
    std::cout << "Parametric generation took " << elapsed.count() << " seconds.\n";

    tic = std::chrono::system_clock::now();
    for (int n = 0; n < N; n++) {
        point_on_circle(x, y, Brute);
    }
    toc = std::chrono::system_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::seconds>(toc - tic);
    std::cout << "Brute force generation took " << elapsed.count() << " seconds.\n";

    return 0;
}