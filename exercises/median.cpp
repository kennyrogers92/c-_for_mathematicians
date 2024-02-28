#include "../Uniform/uniform.h"
#include <iostream>
#include <algorithm>

/**
 * @brief Returns the median of array of real numbers
 * @param array array of real numbers
 * @param nels number of elements of real numbers
 * @return double median of the array
 */
double median(const double* array, long nels) {
    // Corner cases
    // If nels is negative, give a warning and return 0
    if (nels < 0) {
        std::cerr << "Warning: nels cannot be negative" << std::endl;
        return 0.;
    }
    // if nels is zero, return array[0];
    if (nels == 0) return array[0];
    
    // make a copy of the array
    double* copy;
    copy = new double[nels];
    for (int k = 0; k < nels; k++) copy[k] = array[k];

    // sort the copy
    std::sort(copy, copy + nels);

    // extract the median
    double ans;
    if (nels%2 == 1) {
        ans = copy[nels/2];
    }
    else {
        ans = (copy[nels/2] + copy[nels/2 + 1]) / 2.;
    }

    // free the copy
    delete[] copy;
    return ans;
}

int main() {
    seed();
    long n;
    std::cout << "Enter the number of elements in the array --> ";
    std::cin >> n;

    double* array;
    long m = unif(100);
    array = new double[n];
    for (int k = 0; k < n; k++) {
        array[k] = unif(m);
    }

    std::cout << "The elements of the array are ";
    for (int k = 0; k < n; k++) {
        std::cout << array[k] << " ";
    }
    std::cout << "The median of the array is " << median(array, n) << std::endl;
    return 0;
}