/**
 * Author: D Tu Anh
 * Description: short code to compute convolution of 2 sequence work with any mod. n is must power of 2
   \texttt{conv(a, b) = c}, where $c[x] = \sum a[i]b[x-i]$.
 * Time: O(n ^ {\log_2{3}})
 * Status: somewhat tested
 */
const int MOD = 1e9 + 7;
template<int n>
void Mul(int *a, int *b, int *ab) {
    if (n == 1) return ab[0] = 1ll * a[0] * b[0] % MOD, void();
 
    const int m = n >> 1;
    int _a[m], _b[m], _ab[n]{};
    for (int i = 0; i < m; ++i)
        _a[i] = (a[i] + a[i + m]) % MOD,
        _b[i] = (b[i] + b[i + m]) % MOD;
    
    Mul<m>(_a, _b, _ab);
    Mul<m>(a, b, ab);
    Mul<m>(a + m, b + m, ab + n);
 
    for (int i = 0; i < n; ++i)
        _ab[i] = (MOD + MOD + _ab[i] - ab[i] - ab[i + n]) % MOD;
    for (int i = 0; i < n; ++i)
        ab[i + m] = (ab[i + m] + _ab[i]) % MOD;
}
