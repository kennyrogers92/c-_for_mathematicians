#include "PointSegment.h"

Segment Point::operator+(const Point& that) const {
    return Segment(*this, that);
}

Point Segment::midpoint() const {
    double x = (A.getX() + B.getX()) / 2.;
    double y = (A.getY() + B.getY()) / 2.;
    return Point(x, y);
}

std::ostream& operator<<(std::ostream& os, const Point& P) {
    os << "(" << P.getX() << ", " << P.getY() << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Segment& L) {
    os << "[" << L.getA() << ", " << L.getB() << ")";
    return os;
}