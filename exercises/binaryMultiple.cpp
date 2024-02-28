#include <iostream>

/**
 * @brief Simple program to generate the multiple of positive integers
 * less than 1000 consisting ones and zeros. Map an integer 
 * k -> bin2dec(k)
 * where bin2dec is an integer consisting of ones and zeros.
 * Search for the integer k such that bin2dec(k) is divisible 
 * by n. If bin2dec(k) overflows, return -1
 * Note: This could be done in a more brutish manner by checking if the 
 * multiples of n are of the form of zeros and ones.
 */

long long bin2dec(long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return 10*bin2dec(n/2) + (n%2); 
}

long long findBinaryMultiple(long long n) {
    long long k = 1;
    long long m = bin2dec(k);
    while (m > 0) {
        k++;
        m = bin2dec(k);
        if (m % n == 0) return m;
    }   
    return -1;
}

int main() {
    for (long long k = 1; k <= 1000; k++) {
        std::cout << k << "\t" << findBinaryMultiple(k) << std::endl;
    } 
}