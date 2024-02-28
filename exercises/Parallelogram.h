#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include <cmath>

class Parallelogram {
    protected:
        double a, b, c; 
    public:
        // Constructor
        // Default Constructor: Constructs a Parallelogram 
        // with corners (0,0), (1,0), (1, 1), (2,1)
        Parallelogram() {
            a = 1.;
            b = 1.;
            c = 1.;
        }
        
        // Constructs Parallelogram with corners (0,0), (a, 0), (b, c), (a+b,c)
        Parallelogram(double aa, double bb, double cc) {
            if (aa < 0.) aa = -aa;
            if (bb < 0.) bb = -bb;
            a = aa;
            b = bb;
            c = cc;
        }

        // Class methods
        double area () const {
            return a*c;
        }
        
        double perimeter() const {
            return 2.*(sqrt(b*b + c*c) + a);
        }
};

class Rectangle : public Parallelogram {
    public:
        // Constructs rectangle with coordinates (0,0), (x, 0), (0,y), (x,y)
        Rectangle(double x=1., double y=1.0) : Parallelogram(x, 0, y) {};

        double perimeter() const {
            return 2*(a + c);
        } 
};

class Rhombus : public Parallelogram {
    // Constructs rhombus with side lengths sqrt(x^2+y^2)
    Rhombus(double x=1., double y=1.) : Parallelogram(sqrt(x*x+y*x), x, y) {};

    double perimeter() const {
        return 4.*a;
    }
};

#endif