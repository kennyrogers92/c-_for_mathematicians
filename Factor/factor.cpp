#include "factor.h"
#include <iostream>

/**
 * Program to test the factor procedure.
 */
int main() {
    long flist[100];

    for (long n = 1; n <= 100; n++) {
        int nfactors = factor(n, flist);
        std::cout << n << "\t";
        for (int k = 0; k < nfactors; k++) std::cout << flist[k] << " ";
        std::cout << std::endl;
    }
    return 0;
}