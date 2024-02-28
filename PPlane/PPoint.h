/**
 * @file PPoint.h
 * @author kennyrogers (kenraposas92@gmail.com)
 * @brief Class of Points in the Projective Plane
 * @version 0.1
 * @date 2024-02-22
 * @copyright Copyright (c) 2024
 */
#ifndef PPOINT_H
#define PPOINT_H

#include "PObject.h"

class PLine;

class PPoint : public PObject {
    public:
        // Constructors
        PPoint(double a = 0., double b = 0., double c = 1.) : PObject(a, b, c) {}
        PPoint(const PObject& that) : PObject(that.getX(), that.getY(), that.getZ()) {}

        // Equality operator
        bool operator==(const PPoint& that) const {
            return equals(that);
        }

        bool operator!=(const PPoint& that) const {
            return !equals(that);
        }

        // Comparator
        bool operator<(const PPoint& that) const {
            return less(that);
        }

        // Generate a PLine passing through 2 PPoints
        PLine operator+(const PPoint& that) const;

        // Determine if this is on the given PLine 
        bool is_on(const PLine& that) const;
        
        // Generate random line passing through this
        PLine rand_line() const;
};

std::ostream& operator<<(std::ostream& os, const PPoint& P);

inline bool collinear(const PPoint& A, const PPoint& B, const PPoint& C) {
    return dependent(A, B, C);
}

#endif