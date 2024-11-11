/**
 * Author: RR
 * Description: check a point p is on segment [a, b]
 * Both endpoints (p == a or p == b) is also return true.
 */
#include "Point.h"

template<typename T>
bool onSegment(const P<T>& a, const P<T>& b, const P<T>& p) {
    return ccw(a, b, p) == 0
        && min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x)
        && min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}