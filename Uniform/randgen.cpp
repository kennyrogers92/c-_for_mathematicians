#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
     long s;
     cout << "Enter a seed for the random number generator -->" ;
     cin >> s;
     srand(s);
     return 0;
}
