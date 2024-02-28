#include <iostream>
using namespace std;

/**
 * @brief A sample linear congruential pseudo random number generator that returns values from {0, 1, ..., 63}.
 * This procudures shows that Pseudo RNG can be not random.
 * @return int 
 */

int lcg() {
     static int state = 0;
     const long a = 17;
     const long b = 3;
     const long c = 64;
     state = (a*state + b) % c;
     return state;
}

int main() {
     cout << "Values mod 2 : \t\t";
     for (int k = 0; k < 20 ; k++) {
          cout << lcg() % 2 << " ";
     }
     cout << endl;

     cout << "Values mod 4 : \t\t";
     for (int k = 0; k < 20; k++) {
          cout << lcg() % 4 << " ";
     }
     cout << endl;

     cout << "(Alt) Values mod 2 : \t";
     for (int k = 0; k < 20; k++) {
          double x = lcg() / 64.;
          cout << int(2*x) << " ";
     }
     cout << endl;
     return 0;
}
