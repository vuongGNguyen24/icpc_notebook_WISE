/**
 * Author: RR
 * Description: Basic method for Circle, theta is assumed in [0, 2 * PI] using radian.
 * Status: unit tested
 */
#include "Point.h"
struct Circle : Point {
    double r;
    Circle(double _x = 0, double _y = 0, double _r = 0) : Point(_x, _y), r(_r) {}
    Circle(Point p, double _r) : Point(p), r(_r) {}
    bool contains(Point p) { return (*this - p).len() <= r + EPS; }
    double area() const { return r*r*M_PI; }
    double sector_area(double theta) const {
        return 0.5 * r * r * theta;
    }
    double segment_area(double theta) const {
        return 0.5 * r * r * (theta - sin(theta));
    }
};