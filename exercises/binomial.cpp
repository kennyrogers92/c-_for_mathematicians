#include <map>
#include <iostream>
#include <utility>
#include <string>

/**
 * @brief Returns nCk where it is combination of 
 * k elements coming from a set of n elements
 * @param n integer
 * @param k integer
 * @return long nCk
 */
long binomial(long n, long k) {
    // Map to store the computed values of nCk
    static std::map< std::pair<long, long>, long > table;
    
    // Base cases
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;

    std::pair<long, long> args = std::make_pair(n, k);

    // Check if table[args] is already computed
    if (table.count(args) > 0) {
        return table[args];
    }

    // Otherwise, compute it recursively, and record it in map
    table[args] = binomial(n-1, k-1) + binomial(n-1, k); 

    return table[args];
}

/**
 * Program to test binomial procedure 
 */
int main() {
    for (int n = 0; n < 10; n++) {
        std::string line = "";
        for (int k = 0; k < 10; k++) {
            if (binomial(n, k) > 0) {
                line += std::to_string(binomial(n, k)) + "\t";
            }
            else {
                line += "\t";
            }
        }
        std::cout << line << std::endl;
    } 
}