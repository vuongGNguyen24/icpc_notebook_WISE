/**
 * Author: RR
 * Description: return the $A^{-1}$ if $|A| \neq 0$
 * Usage inv(a, n) with n is size of matrix 
 * Time: O(n ^ 3)
 * Status: somewhat tested
 */
const int N = 1003;
vector <bitset<N>> inv(vector <bitset<N>> a, int n)
{
    for (int i = 0; i < n; ++i)
        a[i][n + i] = 1;
    vector<int> where (n, -1);
    for (int col=0, row=0; col< n && row<n; ++col) {
        for (int i=row; i<n; ++i)
            if (a[i][col]) {
                swap (a[i], a[row]);
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
    for (int i = 0; i < n; ++i)
        a[i] >>= n;
    return a;
}