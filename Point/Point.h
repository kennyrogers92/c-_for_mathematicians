/**
 * @file Point.h
 * @author kennyrogers92 (kenraposas92@gmail.com)
 * @brief Point class for 2D Plane in rectangular coordinates
 * @version 0.1
 * @date 2024-02-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef Point_H
#define Point_H

#include <iostream>
#include <cmath>

class Point {
    private:
        double x, y;

    public:
        // Constructors
        // Default Constructor constructs a point at the origin
        Point() {
            x = y = 0.;
        }

        // Construct a point at (xx, yy)
        Point(double xx, double yy) {
            x = xx;
            y = yy;
        }

        double getX() const {
            return x;
        }

        double getY() const {
            return y;
        }

        void setX(double xx) {
            x = xx;
        }

        void setY(double yy) {
            y = yy;
        }

        // Set and get the length R of the point to r
        double getR() const {
            return sqrt(x*x + y*y);
        }

        void setR(double r) {
            // If this point is at the origin, set location to (r, 0)
            if ( (x == 0.) && (y == 0.) ) {
                x = r;
                return;
            }

            // Otherwise, set position as (rcosA, rsinA)
            double A = getA();
            x = r*cos(A);
            y = r*sin(A);
        }

        // Set and get the argument A of the point to theta
        double getA() const {
            if ( (x == 0.) && (y == 0.) ) return 0.;

            double A = atan2(y, x);
            if (A < 0) A +=2*M_PI;
            return A;
        }

        void setA(double theta) {
            double r = getR();
            x = r*cos(theta);
            y = r*sin(theta);
        }

        // Rotates the argument of the point ccw theta radians
        void rotate(double theta) {
            double A = getA();
            A += theta;
            setA(A);
        }
        
        // Equality operators
        bool operator==(const Point& Q) const {
            return ( (x == Q.x) && (y == Q.y) );
        }

        bool operator!=(const Point& Q) const {
            return ! ( (*this) == Q );
        }

        // Comparator by dictionary ordering
        bool operator<(const Point& Q) const {
            if ( x < Q.x || (x == Q.x && y < Q.y) ) return true;
            return false;
        }

        // Translate the point by (dx, dy)
        Point& translate(double dx, double dy) {
            x += dx;
            y += dy;
            return *this;
        }
};

double dist(Point P, Point Q) {
    double dx = P.getX() - Q.getX();
    double dy = P.getY() - Q.getY();
    return sqrt(dx*dx + dy*dy);
}

Point midpoint(Point P, Point Q) {
    double xx = ( P.getX() + Q.getX() ) / 2;
    double yy = ( P.getY() + Q.getY() ) / 2;
    return Point(xx, yy);
}

std::ostream& operator<<(std::ostream& os, const Point& P) {
    os << "(" << P.getX() << "," << P.getY() << ")";
    return os;
}

#endif



