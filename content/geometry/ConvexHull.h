#include "OnSegment.h"

typedef vector< Point > Polygon;
 
// Convex Hull:
// If minimum point --> #define REMOVE_REDUNDANT
// Known issues:
// - Max. point does not work when some points are the same.
// Tested:
// - (min points) https://open.kattis.com/problems/convexhull
// - (max points) https://cses.fi/problemset/task/2195
 
 #define REMOVE_REDUNDANT
template<typename T>
T area2(P<T> a, P<T> b, P<T> c) { return a%b + b%c + c%a; }
 
template<typename T>
void ConvexHull(vector<P<T>> &pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<P<T>> up, dn;
    for (int i = 0; i < (int) pts.size(); i++) {
#ifdef REMOVE_REDUNDANT
        while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
        while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
#else
        while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) > 0) up.pop_back();
        while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) < 0) dn.pop_back();
#endif
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
 
#ifdef REMOVE_REDUNDANT
    if (pts.size() <= 2) return;
    dn.clear();
    dn.push_back(pts[0]);
    dn.push_back(pts[1]);
    for (int i = 2; i < (int) pts.size(); i++) {
        if (onSegment(dn[dn.size()-2], pts[i], dn.back())) dn.pop_back();
        dn.push_back(pts[i]);
    }
    if (dn.size() >= 3 && onSegment(dn.back(), dn[1], dn[0])) {
        dn[0] = dn.back();
        dn.pop_back();
    }
    pts = dn;
#endif
}