/**
 * Author: RR
 * License: CC0
 * Description: Return angle and direct angle for AOB. Only work with P<double> and P<long double>.
 * When using the angle function, be carefull when A, O, B are colinear.
 */
#include "Point.h"
double angle(Point a, Point o, Point b) { // min of directed angle AOB & BOA
    a = a - o; b = b - o;
    auto val = (a * b) / sqrt(a.norm()) / sqrt(b.norm());
    if (cmp(val, -1) == 0)
        return acos(-1);
    if (cmp(val, 1) == 0)
        return acos(1);
    return acos(val);
}

double directed_angle(Point a, Point o, Point b) { // angle AOB, in range [0, 2*PI)
    double t = -atan2(a.y - o.y, a.x - o.x)
            + atan2(b.y - o.y, b.x - o.x);
    while (t < 0) t += 2*PI;
    return t;
}