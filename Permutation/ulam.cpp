#include "Permutation.h"
#include <utility>
#include "../Uniform/uniform.h"

std::pair<long, long> monotone(const Permutation& P) {
    // store the longest increasing and decreasing
    // subsequence starting at given idx, respectively
    long* up;
    long* dn;

    long n = P.getN();

    up = new long[n+1];
    dn = new long[n+1];
    // Initialize all at count 1
    for (long k = 1; k <= n; k++) {
        up[k] = dn[k] =  1;
    }

    // Start from right to left
    for (long k = n-1; k >= 1; k--) {
        // Iterate thru j > k
        for (long j = k+1; j <= n; j++) {
            // If decreases, increment dn[j]
            if (P(k) > P(j)) {
                if (dn[k] <= dn[j]) {
                    dn[k] = dn[j] + 1;
                }
            }
            // Otherwise, increment up[j]
            else {
                if (up[k] <= up[j]) {
                    up[k] = up[j] + 1;
                }
            }
        }
    }

    long up_max = 1;
    long dn_max = 1;
    for (long k = 1; k <= n; k++) {
        if (up_max < up[k]) up_max = up[k];
        if (dn_max < dn[k]) dn_max = dn[k];
    }

    delete[] up;
    delete[] dn;

    return std::make_pair(up_max, dn_max);
}

/**
 * Program to calculate the average lengths of longest increasing
 * and decreasing subsequences of a permutation
 */
int main() {
    long n;
    long reps;
    seed();

    std::cout << "Enter n (size of permutation) --> ";
    std::cin >> n;
    std::cout << "Enter number of repetitions   --> ";
    std::cin >> reps;

    Permutation P(n);
    long sum_up = 0;
    long sum_dn = 0;

    for (long k = 0; k < reps; k++) {
        P.randomize();
        std::pair<long, long> ans;
        ans = monotone(P);
        sum_up += ans.first;
        sum_dn += ans.second;
    }

    std::cout << "Average length of longest increasing subsequence is "
        << double(sum_up) / double(reps) << std::endl;
    std::cout << "Average length of longest decreasing subsequence is "
        << double(sum_dn) / double(reps) << std::endl;

    return 0;
}