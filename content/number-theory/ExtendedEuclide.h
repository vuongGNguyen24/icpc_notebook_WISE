/**
 * Author: RR
 * Source: https://github.com/SnapDragon64/ContestLibrary/blob/master/math.h
 * Description: function to find a solution of the equation ax + by = gcd(a, b). 
 * Status: tested
 * Time: O(\log(max(a, b)))
 */
template<typename T>
T extgcd(T a, T b, T &x, T &y) {
    T g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}