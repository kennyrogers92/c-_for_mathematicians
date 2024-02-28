#include "Interval.h"
#include "../Uniform/uniform.h"

/** Program to investigate the probability that one of the intervals in 
 * I1, I2, ..., In intersects all the others.
 */

/**
 * @brief Returns the largest left endpoint of the intervals
 * @param list array of Intervals
 * @param ni number of intervals
 * @return double largest left endpoint
 */
double find_max_A(const Interval* list, long ni) {
    double ans = list[0].getA();
    for (long k = 1; k < ni; k++) {
        if (ans < list[k].getA()) ans = list[k].getA();
    }
    return ans;
}

/**
 * @brief Returns the smallest right endpoint of the intervals
 * @param list array of Intervals
 * @param ni number of intervals
 * @return double smallest right endpoint
 */
double find_min_B(const Interval* list, long ni) {
    double ans = list[0].getB();
    for (long k = 1; k < ni; k++) {
        if (ans > list[k].getB()) ans = list[k].getB();
    }
    return ans;
}

/**
 * @brief Checks if at least one of the intersects 
 * intersects all of the intervals
 * @param list array of intervals
 * @param ni number of intervals
 * @return true if one interval intersects all
 * @return false otherwise
 */
bool one_meets_all(const Interval* list, long ni) {
    double alpha = find_max_A(list, ni);
    double beta = find_min_B(list, ni);

    for (long k = 0; k < ni; k++) {
        if ( (list[k].getA() <= beta) && (list[k].getB() >= alpha) ) return true;
    }
    return false;
}

int main() {
    seed();
    long ni;
    std::cout << "Enter number of intervals --> ";
    std::cin >> ni;

    long nreps;
    std::cout << "Enter number of repetitions --> ";
    std::cin >> nreps;

    Interval* list;
    list = new Interval[ni];

    long count = 0;
    
    for (long j = 0; j < nreps; j++) {
        for (long k = 0; k < ni; k++) {
            list[k] = Interval(unif(), unif());
        }
        if (one_meets_all(list, ni)) count++;
    }
    
    std::cout << "Success rate: " << 100*double(count) / double(nreps)
        << "%" << std::endl;

    delete[] list;
    return 0;
}