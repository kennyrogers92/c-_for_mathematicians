/**
 * @file PObject.h
 * @author kennyrogers (kenraposas92@gmail.com)
 * @brief Parent class for lines and points in the projective plane
 * @version 0.1
 * @date 2024-02-22
 * @copyright Copyright (c) 2024
 */
#ifndef POBJECT_H
#define POBJECT_H

#include <iostream>
#include <cmath>
#include "../Uniform/uniform.h"

const double default_tolerance = 1e-12;

class PObject {

    private:
        double x, y, z;                         // To hold the coordinates        
        void scale();                           // Helper procedure to scale coordinates to canonical representation
        double dot(const PObject& that) const;  // Dot product of two objects
        static double tolerance;                // for equality measures

    protected:
        // Protected procedure for near-equality using L2-norm
        bool equals(const PObject& that) const;

        // Protected comparator
        bool less(const PObject& that) const;

        // Procedure to determine if the point lies on the line
        bool incident(const PObject& that) const;

        // Generate perpendicular object
        PObject rand_perp() const;

        // Protected procedure a line/point given two points/lines resp.
        PObject op(const PObject& that) const;
    
    public:
        // Constructor
        // Default Constructor: Construct [0,0,1]
        PObject() {
            x = y = 0.;
            z = 1.;
        }

        // Construct [a, b, c]
        PObject(double a, double b, double c) {
            x = a;
            y = b;
            z = c;
            scale();
        }

        // Randomly generate a PObject
        void randomize();

        // Get and set methods
        static void set_tolerance(double t) {
            tolerance = abs(t);
        }

        static double get_tolerance() {
            return tolerance;
        }

        double getX() const {return x;}
        double getY() const {return y;}
        double getZ() const {return z;}

        bool is_invalid() const {
            return (x == 0.) && (y == 0.) && (z == 0);
        }
};

std::ostream& operator<<(std::ostream& os, const PObject& A);

// Determines if three objects are linearly dependent (concurrent, collinear)
bool dependent(const PObject& A, const PObject& B, const PObject& C);

#endif 