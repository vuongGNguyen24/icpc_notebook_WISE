#include "Point.h"

// Segment intersect
// Tested:
// - https://cses.fi/problemset/task/2190/
// returns true if p is on segment [a, b]
template<typename T>
bool onSegment(const P<T>& a, const P<T>& b, const P<T>& p) {
    return ccw(a, b, p) == 0
        && min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x)
        && min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}