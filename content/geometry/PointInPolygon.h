/**
 * Author: RR
 * Description: check a point is in, or out, or on the boundary of a polygon.
 * It works with any polygon and P<double>.
 * Time: O(n)
 * Status: test on https://open.kattis.com/problems/pointinpolygon and
 *  https://open.kattis.com/problems/cuttingpolygon
 */
#include "Point.h"
typedef vector<Point> Polygon;
enum PolygonLocation { OUT, ON, IN };
PolygonLocation in_polygon(const Polygon &p, Point q) {
    if ((int)p.size() == 0) return PolygonLocation::OUT;

    // Check if point is on edge.
    int n = p.size();
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        Point u = p[i], v = p[j];

        if (u > v) swap(u, v);

        if (ccw(u, v, q) == 0 && u <= q && q <= v) return PolygonLocation::ON;
    }

    // Check if point is strictly inside.
    int c = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        if (((p[i].y <= q.y && q.y < p[j].y)
                    || (p[j].y <= q.y && q.y < p[i].y))
                && q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (double) (p[j].y - p[i].y)) {
            c = !c;
        }
    }
    return c ? PolygonLocation::IN : PolygonLocation::OUT;
}