/**
 * Author: RR
 * Source: https://cp-algorithms.com/linear_algebra/linear-system-gauss.html
 * Description: function to solve $Ax = b$ in modulo 2, with last column of a is vector b, return number of solution and a solution. 0 index base
 * Usage gauss(a, n, m, ans) with n is number of equations, m is number of vars. 
 * Time: O(n ^ 2 \times m)
 * Status: somewhat tested
 */
const int N = 502, INF = 1e9;
int gauss (vector < bitset<N> > a, int n, int m, bitset<N> & ans)
{
    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col)
    {
        for (int i=row; i<n; ++i)
            if (a[i][col])
            {
                swap(a[i], a[row]);
                break;
            }
        if (!a[row][col])
            continue;
        where[col] = row;
 
        for (int i=0; i<n; ++i)
            if (i != row && a[i][col])
                a[i] ^= a[row];
        ++row;
    }
    for (int i = 0; i < m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i = 0; i < n; ++i)
    {
        int sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs(sum - a[i][m]) > 0)
            return 0;
    }
    // If we need any solution (in case INF solutions), we should be
    // ok at this point.
    // If need to solve partially (get which values are fixed/INF value):
//    for (int i=0; i<m; ++i)
//        if (where[i] != -1) {
//            REP(j,n) if (j != i && fabs(a[where[i]][j]) > EPS) {
//                where[i] = -1;
//                break;
//            }
//        }
    // Then the variables which has where[i] == -1 --> INF values
    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}

