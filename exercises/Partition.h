/**
 * @file Partition.h
 * @author kennyrogers (kenraposas92@gmail.com)
 * @brief Partition class to represent integer partitions
 * @version 0.1
 * @date 2024-02-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef PARTITION_H
#define PARTITION_H

#include <set>
#include <iostream>
#include <vector>

class Partition {
    private:
        // A multiset to hold the parts
        std::multiset<int> parts;
        // An integer to hold the sum
        int sum;
    public:
        // Constructors
        /// Default Constructor: construct null partition of 0
        Partition() {
            sum = 0;
            parts.clear();
        } 

        /// Add a new part to this partition
        void add_part(int n) {
            if (n <= 0) {
                std::cerr << "Warning: Cannot add nonpositive part to a partition" << std::endl;
                return;
            }
            parts.insert(n);
            sum += n;
        }

        /// Sum of the parts
        int get_sum() const {
            return sum;
        }

        /// Number of parts in this partition
        int nparts() const {
            return parts.size();
        }

        /// Get a vector containing the parts
        std::vector<int> get_parts() const {
            std::vector<int> ans;
            ans.resize(nparts());
            std::multiset<int>::iterator pi;
            int idx = 0;
            for (pi = parts.begin(); pi != parts.end(); pi++) {
                ans[idx] = *pi;
                ++idx;
            }
            return ans;
        }

        /// Compare two parts
        bool operator<(const Partition& that) const {
            // First compare the number partitioned
            if (sum < that.sum) return true;
            if (sum > that.sum) return false;

            // Compare the parts
            if (nparts() < that.nparts()) return true;
            if (nparts() > that.nparts()) return false;

            // Compare element by element
            std::vector<int> my_parts = get_parts();
            std::vector<int> that_parts = that.get_parts();

            for (int k = 0; k < nparts(); k++) {
                if (my_parts[k] < that_parts[k]) return true;
                if (my_parts[k] > that_parts[k]) return false;
            }
            return false;
        }

        
};

std::ostream& operator<<(std::ostream& os, const Partition& P) {
    if (P.get_sum() == 0) {
        os << 0;
        return os;
    }

    std::vector<int> list = P.get_parts();
    int np = P.nparts();
    os << P.get_sum() << " = ";
    for (int i = np-1; i >= 0; i--) {
        os << list[i];
        if (i > 0) os << "+";
    }
    return os;
}

/**
 * @brief Recursively generate the set of all partitions of n
 * whose largest part is at most mp
 * @param n integer to partition
 * @param mp largest possible part of the partition
 * @return std::set<Partition> 
 */
std::set<Partition> make_partitions(int n, int mp) {
    std::set<Partition> ans;
    std::set<Partition> tmp;

    if (mp > n) mp = n;

    if (n == 0) {
        ans.insert(Partition());
        return ans;
    }

    for (int k = 1; k <= n; k++) {
        tmp.clear();
        tmp = make_partitions(n - k, k);
        std::set<Partition>::iterator sp;
        for (sp = tmp.begin(); sp != tmp.end(); sp++) {
            Partition P = *sp;
            P.add_part(k);
            ans.insert(P);
        }
    }
    return ans;
}

/**
 * @brief Generic function to generate all partitions
 * of an integer n
 * @param n integer to partition
 * @return std::set<Partition> partition of n
 */
std::set<Partition> make_partitions(int n) {
    return make_partitions(n, n);
}

#endif