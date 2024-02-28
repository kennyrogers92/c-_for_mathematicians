#include "PTriple.h"
#include <cmath>
#include <algorithm>

/**
 * @brief Find all primitive Pythagorean triples (a, b, c) with 
 * 0 <= a <= b <= c <= N where N is specified by the user. 
 * It reports the wrong number of values of unique primitive
 * Pythagorean triples due to duplicates in the arrays. This can
 * be resolved by using set instead of arrays.
 */

int main() {
    PTriple* table;
    long N;

    // Ask that user for N
    std:: cout << "Please enter N (upper bound on triples) -- > ";
    std::cin >> N;
    if (N <= 0) return 0;

    // Allocate space for the table
    table = new PTriple[N];

    // Populate the table with all possible PTriples
    long idx = 0;
    long rootN = long(sqrt(double(N)));

    for (long n = 1; n <= rootN; n++) {
        for (long m = n+1; m <= rootN; m++) {
            PTriple P = PTriple(m, n);
            if (P.getC() <= N) {
                table[idx] = P;
                idx++;
            } 
        } 
    }

    // Sort the table
    std::sort(table, table+idx);

    std::cout << "There are " << idx << " primitive Pythagorean Triples"
        << " less than " << N << std::endl; 
    std::cout << "These are" << std::endl;
    // Print out nonduplicate elements of the table
    std::cout << table[0] << std::endl;
    for (int k = 1; k < idx; k++) {
        if (table[k] != table[k-1]) {
            std::cout << table[k] << std::endl;
        }
    }

    // Release memory
    delete[] table;
    return 0;
}