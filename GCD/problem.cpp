#include <iostream>
#include <string>
#include <cmath>
#include "gcd.h"
using namespace std;

/**
 * Find the probability that two integers in {1,...,n} are relatively prime.
 */
int main() {
     long t = 5;
     
     std::cout << std::string(20, '-') << std::endl;
     std::cout << "n\tp_n" << std::endl;
     for (long i = 1; i <= t; i++) {
          long n = std::pow(10, i);
          long count = 0;
          for (long a=1; a<=n; a++) {
               for (long b=a+1; b<=n; b++) {
                    if (gcd(a, b, Iterative) == 1) {
                         count++;
                    }
               }
          }
          count = 2*count + 1;
          
          cout <<  n << "\t" << double(count) / (double(n) * double(n)) << endl;
     }
     std::cout << std::string(20, '-') << std::endl;
     return 0; 
}
