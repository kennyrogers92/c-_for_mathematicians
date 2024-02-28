/**
 * @file PointSegment.h
 * @author kennyrogers (kenraposas92.com)
 * @brief Class for Point and Line Segment
 * @version 0.1
 * @date 2024-02-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef POINTSEGMENT_H
#define POINTSEGMENT_H

#include <iostream>

class Segment;

class Point {
    private:
        double x, y;
    public:
        // Constructors
        // Default: (0,0)
        Point() {
            x = y = 0.;
        }

        // Construct (xx, yy)
        Point(double xx, double yy) {
            x = xx;
            y = xx;
        }

        // Get methods
        double getX() const {
            return x;
        }

        double getY() const {
            return y;
        }

        // Segment passing thru two points
        Segment operator+(const Point& that) const;
};

class Segment {
    private:
        Point A, B;
    public:
        // Constructor
        // Default: Line segment from origin to (1,0)
        Segment() {
            A = Point();
            B = Point(1,0);
        }

        // Construct: Segment from P to Q
        Segment(Point P, Point Q) {
            A = P;
            B = Q;
        }

        // Get methods
        Point getA() const {
            return A;
        }

        Point getB() const {
            return B;
        }

        Point midpoint() const;
};

std::ostream& operator<<(std::ostream& os, const Point& P);
std::ostream& operator<<(std::ostream& os, const Segment& L);

#endif