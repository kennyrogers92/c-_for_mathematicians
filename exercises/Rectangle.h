/**
 * @file Rectangle.h
 * @author kennyrogers (kenraposas92@gmail.com)
 * @brief Rectangle class
 * @version 0.1
 * @date 2024-02-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

class Rectangle {
    protected:
        double height;
        double width;
    public:
        // Constructor 
        Rectangle(double h=1., double w=1.) {
            height = h;
            width = w;
        }

        // Get and set methods
        double getHeight() const {
            return height;
        }

        double getWidth() const {
            return width;
        }

        void setHeight(double h) {
            height = h;
        }

        void setWidth(double w) {
            width = w;
        }

        double area() {
            return height*width;
        }

        double peri() {
            return 2.*(height + width);
        }

        // Equality operator
        bool operator==(const Rectangle& R) const {
            return (height== R.height) && (width == R.width);
        }

        bool operator!=(const Rectangle& R) const {
            return !(*this == R);
        }

        bool isSquare() const {
            return (height == width);
        }
};

std::ostream& operator<<(std::ostream& os, Rectangle& R) {
    os << "Rectangle with height " << R.getHeight() << " and width " << R.getWidth();
    os << std::endl << "Its area is " << R.area() << " and perimeter is " << R.peri();
    return os;
}

#endif