/**
 * @file PLine.h
 * @author kennyrogers (kenraposas92@gmail.com)
 * @brief Class of Lines in the Projective Plane
 * @version 0.1
 * @date 2024-02-22
 * @copyright Copyright (c) 2024
 */
#ifndef PLINE_H
#define PLINE_H

#include "PObject.h"

class PPoint;

class PLine : public PObject {
    public:
        // Constructor
        PLine(double a = 0., double b = 0., double c = 1.) : PObject(a, b, c) {}
        PLine(const PObject& that) : PObject(that.getX(), that.getY(), that.getZ()) {}
        
        // Equality operator
        bool operator==(const PLine& that) const {
            return equals(that);
        }

        bool operator!=(const PLine& that) const {
            return !equals(that);
        }

        // Comparator
        bool operator<(const PLine& that) const {
            return less(that);
        }

        // Generate a PPoint which is the intersection of two PLines
        PPoint operator*(const PLine& that) const;

        // Determine if this has given PPoint
        bool has(const PPoint& that) const;

        // Generate random point on this
        PPoint rand_point() const;
};

std::ostream& operator<<(std::ostream& os, const PLine& P);

inline bool concurrent(const PLine& A, const PLine& B, const PLine& C) {
    return dependent(A, B, C);
}

#endif