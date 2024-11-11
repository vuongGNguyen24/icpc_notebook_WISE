/**
 * Author: RR
 * Description: Function for check point in convex polygon
 * Time: O(\log n)
 */
#include "OnSegment.h"
#include "PointInPolygon.h"

#define Det(a,b,c) ((double)(b.x-a.x)*(double)(c.y-a.y)-(double)(b.y-a.y)*(c.x-a.x))
PolygonLocation in_convex(vector<Point>& l, Point p){
    int a = 1, b = l.size()-1, c;
    if (Det(l[0], l[a], l[b]) > 0) swap(a,b);

    if (onSegment(l[0], l[a], p)) return ON;
    if (onSegment(l[0], l[b], p)) return ON;

    if (Det(l[0], l[a], p) > 0 || Det(l[0], l[b], p) < 0) return OUT;
    while(abs(a-b) > 1) {
        c = (a+b)/2;
        if (Det(l[0], l[c], p) > 0) b = c; else a = c;
    }
    int t = cmp(Det(l[a], l[b], p), 0);
    return (t == 0) ? ON : (t < 0) ? IN : OUT;
}