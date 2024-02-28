/**
 * @file Square.h
 * @author kennyrogers (kenraposas92@gmail.com)
 * @brief Square class
 * @version 0.1
 * @date 2024-02-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

class Square : public Rectangle {
    public:
        // Constructor
        Square(double s = 1.) : Rectangle(s, s) {}

        // Get and set methods
        void setHeight(double s) {
            height = s;
            width = s;
        }

        void setWidth(double s) {
            Square::setHeight(s);
        }

        // Equality operator
        bool operator==(const Square& S) const {
            return height == S.height;
        }

        bool operator==(const Rectangle& R) const {
            if (!R.isSquare()) return false;
            return height == R.getHeight();
        }
};

bool operator==(const Rectangle& R, const Square& S) {
    return (S == R);
}

std::ostream& operator<<(std::ostream& os, Square& S) {
    os << "Square with side length " << S.getHeight() << std::endl;
    os << "Its area is " << S.area() << " and perimeter is " << S.peri();
    return os;
}

#endif