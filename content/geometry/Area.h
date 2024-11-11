/**
 * Author: RR
 * Description: Find the area of any polygon
 * Time: O(n)
 */
#include "PointInPolygon.h"
template<typename T>
T signed_area2(vector<P<T>> p) {
    T area(0);
    for(int i = 0; i < (int) p.size(); i++) {
        area += p[i] % p[(i + 1) % p.size()];
    }
    return area;
}
double area(const Polygon &p) {
    return std::abs(signed_area2(p) / 2.0);
}