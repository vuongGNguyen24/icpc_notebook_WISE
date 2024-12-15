/**
 * Author: Vuong Nguyen
 * Description: Assume the point M is outside the circle C, find 2 tangents from M to C. If M in on the circle, the function return 2 tangenets present the same line.
 * Status: test on https://codeforces.com/gym/102021 - problem B
 */
#include "Point.h"
#include "Line.h"
#include "Circle.h"
template <class T> T sqr(T x) {return x * x;}

pair<double, double> solve(double a, double b, double c)
{
    auto d = b * b - 4 * a * c;
    assert(d >= 0);
    return {(-b + sqrt(d)) / 2 / a, (-b - sqrt(d)) / 2 / a};
}
vector <Line> tangents(Point p, Circle c) {
    auto [x0, y0] = p;
    auto a = c.x, b = c.y, r = c.r;
    int m = a - x0, n = b - y0;
    // d != 0 -> d = 1
    if (cmp(sqr(m) - sqr(r), 0))
    {
        auto [c1, c2] = solve(sqr(m) - sqr(r), 2 * m * n, sqr(n) - sqr(r));
        vector <Line> res;
        res.push_back({c1, 1, -c1 * x0 - y0});
        res.push_back({c2, 1, -c2 * x0 - y0});
        return res;
    }
    // d == 0
    else
    {
        auto [d1, d2] = solve(sqr(n) - sqr(r), 2 * m * n, 0);
        vector <Line> res;
        res.push_back({1, d1, -x0 - d1 * y0});
        res.push_back({1, d2, -x0 - d2 * y0});
        return res;
    }
}