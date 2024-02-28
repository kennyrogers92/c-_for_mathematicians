/**
 * @file LineSegment.h
 * @author kennyrogers92 (kenraposas92@gmail.com)
 * @brief Line Segment Class for 2D Line Segments
 * @version 0.1
 * @date 2024-02-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef LINE_SEGMENT_H
#define LINE_SEGMENT_H

#include <iostream>
#include "Point.h"

class LineSegment {
    private:
        // endpoints of the segment
        Point A;
        Point B;
    public:
        // Constructors
        // Default constructor creates a singleton containing the origin
        LineSegment() {
            A = Point();
            B = Point();
        }

        // Construct LineSegment from two distinct points
        LineSegment(Point P, Point Q) {
            if (Q < P) {
                Point R = Q;
                Q = P;
                P = R;
            }
            A = P;
            B = Q;
        }

        // Construct LineSegment from four floats
        LineSegment(double x1, double y1, double x2, double y2) {
            Point P (x1, y1);
            Point Q (x2, y2);
            *this = LineSegment(P, Q);
        }

        // Get and set methods
        Point getA() const {
            return A;
        }

        Point getB() const {
            return B;
        }

        void setA(Point P) {
            A = P;
        }

        void setB(Point Q) {
            B = Q;
        }

        // Length and midpoint methods
        double length() const {
            double dx = B.getX() - A.getX();
            double dy = B.getY() - A.getY();
            return sqrt(dx*dx + dy*dy);
        }

        Point midpoint() {
            return Point( (A.getX() + B.getX())/2., (A.getY() + B.getY())/2.);
        }

        // Equality operator
        bool operator==(const LineSegment& that) {
            if ( (A == that.A) && (B == that.B) ) return true;
            return false;
        }

};

std::ostream& operator<<(std::ostream& os, const LineSegment& L) {
    os << L.getA() << "->" << L.getB();
    return os;
}

#endif