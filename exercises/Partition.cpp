#include "Partition.h"

/**
 * Program to test the Partition class
 */
int main() {
    std::cout << "Enter n: ";
    int n;
    std::cin >> n;

    std::set<Partition> PS = make_partitions(n);
    std::set<Partition>::iterator pp;
    for (pp = PS.begin(); pp != PS.end(); pp++) {
        std::cout << *pp << std::endl;
    }
    std::cout << PS.size() << " partitions of " << n << std::endl;
    return 0;
}