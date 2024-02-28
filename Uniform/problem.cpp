#include <iostream>
#include "uniform.h"
#include "../GCD/gcd.h"
using namespace std;

/**
 * @brief This main generates many pairs of values from the set {1, 2, ..., n}
 * and reports how often the pairs are relatively prime. The value n and the number
 * of pairs are specified by the user. Choose the number of repetitions to be less
 * than nC2
 * @return int 
 */

int main() {
     long n;
     long reps;
     long a,b;
     long count;

     count = 0;

     cout << "Enter n (maximum el't of the set) --> "; cin >> n;
     cout << "Enter the number of pairs to sample -- > ";cin >> reps;

     for (long k = 1; k < reps; k++) {
          a = unif(n);
          b = unif(n);
          if (gcd(a,b, Iterative) == 1) count++;
     }
     cout << count / double(reps);
     return 0;
}
