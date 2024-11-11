/**
 * Author: Vuong Nguyen
 * Source: folklore
 * Description: Computes prefix sum of regtangle $(1, 1)$ to $(x, y)$ and updates single elements a[x][y] by taking the difference between the old and new value. Note that index is from 1.
 * Time: Both operations are O(\log^2 n).
 * Status: Stress-tested
 */
using ll = long long;
struct BIT2D
{
    vector <vector <ll>> a;
    int n, m;
    BIT2D(int _n, int _m)
    {
        n = _n, m = _m;
        a.resize(n + 1, vector <ll>(m + 1, 0));
    }
    void add(int x, int y, long long val)
    {
        for (int i = x; i <= n; i += i & -i)
        {
            for (int j = y; j <= m; j += j & -j)
                a[i][j] += val;
        }
    }
    ll get(int x, int y)
    {
        ll res = 0;
        for (int i = x; i; i -= i & -i)
        {
            for (int j = y; j; j -= j & -j)
                res += a[i][j];
        }
        return res;
    }
};