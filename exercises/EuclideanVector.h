/**
 * @file EuclideanVector.h
 * @author kennyrogers (kenraposas92@gmail.com)
 * @brief Class implementation of Euclidean Vector
 * @version 0.1
 * @date 2024-02-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef EUCLIDEAN_VECTOR_H
#define EUCLIDEAN_VECTOR_H

#include <vector>
#include <iostream>

const long INITIAL_DEFAULT_DIM = 2;

class EuclideanVector{
    private:
        long dim;                       // To hold the dimension of a vector
        std::vector<double> vector;     // To hold the elements of a vector
        static long default_dim;
    public:
        // Constructors
        // Default Constructor: Construct zero vector in default dimension
        EuclideanVector() {
            dim = default_dim;
            vector.resize(dim);
            for (int i = 0; i < dim; i++) vector[i] = 0.;
        }

        // Constructs zero vector in Rn
        EuclideanVector(long n) {
            if (n < 0) {
                std::cout << "Warning: dimension cannot be negative" << std::endl
                    << "using zero instead" << std::endl;
                n = 0;
            }
            dim = n;
            vector.resize(n);
            for (int i = 0; i < dim; i++) vector[i] = 0.;
        }

        // Get and set methods
        double get(long k) const {
            if (k < 0 || k > dim - 1) {
                std::cerr << "Warning: idx out of bounds." << std::endl;
                return 0.;
            }
            return vector[k];
        }

        void set(long k, double x) {
            if (k < 0 || k > dim - 1) {
                std::cerr << "Warning: idx out of bounds." << std::endl;
                return;
            }
            vector[k] = x;
        }

        long get_dim() const {
            return dim;
        }

        static void set_default_dim(long n) {
            if (n < 0) {
                std::cerr << "Default dimension cannot be negative" << std::endl    
                    << "Using zero instead" << std::endl;
                n = 0;
            }
            default_dim = n;
        }

        static long get_default_dim() {
            return default_dim;
        }

        // Arithmetic Operations
        EuclideanVector operator+(const EuclideanVector& that) const {
            // Check if dimensions are equal
            if (dim != that.dim) {
                std::cerr << "Warning: Dimensions do not match" << std::endl;
                return EuclideanVector(0);
            }
            EuclideanVector V(dim);
            for (int k = 0; k < dim; k++) {
                V.vector[k] = vector[k] + that.vector[k];
            }
            return V;
        }

        EuclideanVector operator+=(const EuclideanVector& that) const {
            return *this + that;
        }

        EuclideanVector operator-() const {
            EuclideanVector V(dim);
            for (int k = 0; k < dim; k++) {
                V.vector[k] = -vector[k];
            }
            return V;
        }

        EuclideanVector operator-(const EuclideanVector& that) const {
            return *this + (-that);
        }

        EuclideanVector operator-=(const EuclideanVector& that) const {
            return *this - that;
        }

        EuclideanVector operator*(double a) const {
            // Corner case
            if (a == 0.) return EuclideanVector();
            
            EuclideanVector V(dim);
            for (int i = 0; i < dim; i++) {
                V.vector[i] = vector[i]*a;
            }
            return V;
        }

        // Equality Operator
        bool operator==(const EuclideanVector& that) const {
            // Check if dimensions match
            if (dim != that.dim) return false;
            for (int k = 0; k < dim; k++) {
                if (vector[k] != that.vector[k]) return false;
            }
            return true;
        }

        bool operator!=(const EuclideanVector& that) const {
            return !(*this == that);
        }
};

long EuclideanVector::default_dim = INITIAL_DEFAULT_DIM;

EuclideanVector operator*(double a, const EuclideanVector& V) {
    return V*a;
}

std::ostream& operator<<(std::ostream& os, const EuclideanVector& V) {
    os << "[";
    for (int k = 0; k < V.get_dim()-1; k++) {
        os << V.get(k) << " ";
    }
    os << V.get(V.get_dim()-1) << "]";
    return os;
}

#endif