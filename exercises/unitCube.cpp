#include <vector>
#include <iostream>

#include "../Uniform/uniform.h"

typedef std::vector<double> C3;

C3 randomize() {
    C3 V;
    for (int i = 0; i < 3; i++) {
        V.push_back(unif());
    }
    return V;
}

bool operator<(const C3& A, const C3& B) {
    if (A[0] < B[0]) return true;
    if (A[0] > B[0]) return false;
    if (A[1] < B[1]) return true;
    if (A[1] > B[1]) return false;
    if (A[2] < B[2]) return true;
    return false;
}

void print_coords(const C3& A) {
    std::cout << "(";
    for (int i = 0; i < 2; i++) {
        std::cout << A[i] << ", ";
    }
    std::cout << A[2] << ")" << std::endl;
}

int main() {

    seed();
    
    // Vector to hold C3s
    std::vector<C3> points;

    // number of points
    long n;
    std::cout << "Enter the number of points to be generated --> ";
    std::cin >> n;

    std::cout << "Generating " << n << " number of points" << std::endl;

    for (long k = 0; k < n; k++) {
        points.push_back( randomize() );
        print_coords(points[k]);
    }

    std::cout << n << " numbers of points generated" << std::endl;

    long longest = 1;
    long current = 1;
    for (long k = 0; k < n-1; k++) {
        if (points[k] > points[k+1]) {
            if (longest < current) {
                longest = current;
            }
            current = 1;
        }
        else {
            current++;
        }
    }
    
    std::cout << "The size of the largest increasing subset is " << longest;
    std::cout << "\nThe ratio is " << double(longest)/double(n) << std::endl;
}