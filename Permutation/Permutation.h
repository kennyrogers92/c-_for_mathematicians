/**
 * @file Permutation.h
 * @author kennyrogers (kenraposas92@gmail.com)
 * @brief Class to represent permutations (a bijection of from the
 * set {1, 2, ..., n}) to itself. Permutations are represented by
 * int n, the length of the permutation and
 * array of integers (length n + 1) data.
 * @version 0.1
 * @date 2024-02-25
 * 
 * @copyright Copyright (c) 2024
 */
#ifndef PERMUTATION_H
#define PERMUTATION_H

#include <iostream>
#include <vector>

class Permutation {
    private:
        long n;         // length of array
        long* data;     // values under permutation

    public:
        /// Constructors
        // Default constructor: identity permutation of 1 elt
        Permutation();

        // Construct identity permutation of nels elements
        Permutation(long nels);

        // Construct permutation defined by array of nels elements
        Permutation(long nels, long* array);

        // Copy constructor
        Permutation(const Permutation& that);

        // Destructor
        ~Permutation();

        // Class methods
        // Swaps images of i and j under permutation
        void swap(long i, long j);

        // Uniformly randomize permutation of length n
        void randomize();

        // Set permutation to be the identity permutation of length n
        void reset();

        // Checks if this is a valid permutation
        bool check() const;

        // Get length of array
        long getN() const {return n;}

        // Get the image of k under this permutation
        long of(long k) const;
        long operator()(long k) const {return of(k);}

        // Assignment operator
        Permutation operator=(const Permutation& that);

        // Product of permutations this and that
        Permutation operator*(const Permutation& that) const;
        Permutation operator*=(const Permutation& that);

        // Inverse of this permutation
        Permutation inverse() const;

        // Equality operators
        bool operator==(const Permutation& that) const;
        bool operator!=(const Permutation& that) const;

        // Comparator: compares length then lexicographically compares the array
        bool operator< (const Permutation& that) const;
        
        // Checks if this permutation is the identity
        bool isIdentity() const;

        // Returns the permutation in cycle notation using vector
        std::vector< std::vector<long> > to_cycle() const;

        // Returns the order of this permutation
        long order() const;
        
};

std::ostream& operator<<(std::ostream& os, const Permutation& P);

#endif 