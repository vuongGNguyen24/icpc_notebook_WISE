/**
 * Author: RR
 * Description: Check 2 segment is intersect or not (including end points)
 * Status: test on https://cses.fi/problemset/task/2190/
 */
#include "OnSegment.h"
template<typename T>
bool segmentIntersect(const P<T>& a, const P<T>& b, const P<T>& c, const P<T>& d) {
    if (onSegment(a, b, c)
            || onSegment(a, b, d)
            || onSegment(c, d, a)
            || onSegment(c, d, b)) {
        return true;
    }

    return ccw(a, b, c) * ccw(a, b, d) < 0
        && ccw(c, d, a) * ccw(c, d, b) < 0;
}