#include ".\template.h"
/**
 * Author: Vuong Nguyen
 * Source: notebook RR
 * Description: Class to handle points in the plane. T can be e.g. double or long long. (Avoid int.)
 */

const double EPS = 1e-6;
const double PI = acos(-1.0); 
template <class T1, class T2> int cmp(T1 x, T2 y)
{
    if constexpr (is_floating_point<T1>() || is_floating_point<T2>())
        return x < y - EPS? -1: (x > y + EPS? 1: 0);
    else
        return x < y? -1: (x == y? 0: 1);
}
template<typename T>
struct P {
    T x, y;
    P() { x = y = T(0); }
    P(T _x, T _y) : x(_x), y(_y) {}
 
    P operator + (const P& a) const { return P(x+a.x, y+a.y); }
    P operator - (const P& a) const { return P(x-a.x, y-a.y); }
    P operator * (T k) const { return P(x*k, y*k); }
    P<double> operator / (double k) const { return P(x/k, y/k); }
 
    T operator * (const P& a) const { return x*a.x + y*a.y; } // dot product
    T operator % (const P& a) const { return x*a.y - y*a.x; } // cross product
 
    int cmp(const P<T>& q) const { if (int t = ::cmp(x,q.x)) return t; return ::cmp(y,q.y); }
 
    #define Comp(x) bool operator x (const P& q) const { return cmp(q) x 0; }
    Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)
    #undef Comp
 
    T norm() { return x*x + y*y; }
 
    // Note: There are 2 ways for implementing len():
    // 1. sqrt(norm()) --> fast, but inaccurate (produce some values that are of order X^2)
    // 2. hypot(x, y) --> slow, but much more accurate
    double len() { return hypot(x, y); }
 
    P<double> rotate(double alpha) {
        double cosa = cos(alpha), sina = sin(alpha);
        return P(x * cosa - y * sina, x * sina + y * cosa);
    }
};
using Point = P<double>;

template<typename T>
int ccw(P<T> a, P<T> b, P<T> c) {
    return cmp((b-a)%(c-a), T(0));
}