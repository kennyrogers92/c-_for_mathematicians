/**
 * @file Line.h
 * @author kennyrogers92 (kenraposas92@gmail.com)
 * @brief Line class for 2D Plane in standard form: ax+by+c=0
 *  where a and b are not both zero
 * @version 0.1
 * @date 2024-02-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef LINE_H
#define LINE_H

#include "Point.h"

class Line {
    private:
        double a, b, c;
    public:
        // Constructors;
        // Default constructor y = 0
        Line() {
            a = c = 0;
            b = 1;
        }

        // Constructor by a, b, c
        Line(double aa, double bb, double cc) {
            // Check if a and b are not both zero
            // Otherwise, return y+c=0
            if ( (a == 0.) && (b == 0.) ) {
                std::cerr << "Warning: Invalid call to Line(a, b, c)" << std::endl;
                a = 0.;
                b = 1.;
                c = c;
                return;
            }
            a = aa;
            b = bb;
            c = cc;
        }

        // Constructor from two given points
        Line(Point P, Point Q) {
            double x1 = P.getX();
            double y1 = P.getY();
            double x2 = Q.getX();
            double y2 = Q.getY();

            // If the points are the same, make the Line horizontal
            // through the one point
            if (P == Q) {
                std::cerr << "Warning: Constructing Line from two equal Points" << std::endl;
                a = 0.;
                b = 1.;
                c = -y1;
                return;
            }
            
            // If the points are distinct, continue starting with the
            // case of vertical line (x1 = x2)
            else if (x1 == x2) {
                a = 1.0;
                b = 0.;
                c = -x1;
                return;
            }

            // The points are distinct and not vertical
            else {
                a = y2 - y1;
                b = x1 - x2;
                c = x2*y1 - x1*x2;
            }
        }

        // Get Methods
        double getA() const {
            return a;
        }
        
        double getB() const {
            return b;
        }

        double getC() const {
            return c;
        }
        
        // Reflect Methods
        Line reflectX() {
            b = -b;
            return *this;
        }

        Line reflectY() {
            a = -a;
            return *this;
        }

        // Check if a Point is on this Line 
        bool incident(const Point P) const {
            return (a*P.getX() + b*P.getY() + c == 0);
        }

        // Generate a Point on a Line
        Point find_Point() const {
            // If it's a vertical line, return x-intercept
            if (b == 0.) {
                return Point(-c/a, 0);
            }
            // Otherwise, return the y-intercept
            return Point(0, -c/b);
        }

        bool operator==(const Line& that) const {
            // Case when a=0
            if (a == 0.) {
                if ( that.a != 0.) return false;
                return c/b == that.c/that.b;
            }
            
            // When a!=0
            if (that.a == 0.) return false;
            return (b/a == that.b/that.a) && (c/a == that.c/that.a);
        }
};

// Write to an output stream
std::ostream& operator<<(std::ostream& os, const Line& l) {
    os << l.getA() << "x +" << l.getB() << "y + " << l.getC() << " = 0" << std::endl; 
    return os;
}

// Compute the distance from a Point to a Line
double dist(Line L, Point P) {
    // get a, b, c, for the line
    double a = L.getA();
    double b = L.getB();
    double c = L.getC();

    // get coordinates of the point
    double x = P.getX();
    double y = P.getY();

    // Normalize the Line
    double d = sqrt(a*a + b*a);
    a /= d;
    b /= d;
    c /= d;

    // Project P onto the unit vector (a, b) and add c
    double ans = x*a + y*b + c;

    return fabs(ans);
}

double dist(Point P, Line L) {
    return dist(L, P);
}

// Return if two lines intersect or not
bool intersect(Line L, Line M, Point& P) {
    // get coefficients of the lines
    double La = L.getA();
    double Lb = L.getB();
    double Lc = L.getC();
    double Ma = M.getA();
    double Mb = M.getB();
    double Mc = M.getC();

    // Case when Line L is horizontal
    if (La == 0.) {
        // Case when Line M is also horizontal
        if (Ma == 0.) {
            return false;
        }
        // If Line M is not horizontal
        else {
            P.setX( (Lc*Mb)/(Ma*Lb) - Mc/Ma );
            P.setY( -Lc/La );
            return true;
        }
    }

    // Case when Line L is not horizontal
    // Subcase when Line M is horizontal
    if (Ma == 0) {
        P.setX( (Lb*Mc)/(Mb*La) - Lc/La );
        P.setY( -Mc/Mb);
        return true;
    }
    // Subcase when Line M is not horizontal
    // Case when both lines have the same slope
    if (Lb/La == Mb/Ma) {
        return false;
    }
    double y = (Ma*Lc - La*Mc)/(La*Mb - Ma*Lb);
    P.setX( -Lb/La*y - Lc/La );
    P.setY(y);
    return true;
}

#endif