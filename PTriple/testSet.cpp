#include "PTriple.h"
#include <cmath>
#include <set>

int main() {
    std::set<PTriple> S;

    // Ask the user for N
    std::cout << "Please enter N (upper bound on triples) --> ";
    long N;
    std::cin >> N;
    if (N <= 0) return 0;

    long rootN = long(sqrt(double(N)));

    for (int n = 1; n <= rootN; n++) {
        for (int m = n+1; m <= rootN; m++) {
            PTriple P(m, n);
            if (P.getC() <= N) S.insert(P);
        }
    }

    std::cout << "There are " << S.size() << " primitive Pythagorean Triples"
        << " less than " << N << std::endl; 
    std::cout << "These are" << std::endl;
    // Print the elements of the set
    std::set<PTriple>::const_iterator si;
    for (si = S.begin(); si != S.end(); si++) {
        std::cout << *si << std::endl;
    }

    return 0;
}