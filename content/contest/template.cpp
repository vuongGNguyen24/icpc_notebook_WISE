#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define PR(a,n) { cerr << #a << " = "; FOR(_,1,n) cerr << a[_] << ' '; cerr << endl; }
#define PR0(a,n) { cerr << #a << " = "; FOR(_, 0, n - 1) cerr << a[_] << ' '; cerr << endl; }
#define debug(x) cerr << #x << " = " << x << endl
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define __builtin_popcount __builtin_popcountll
typedef unsigned long long ull;
typedef pair<int, int> ii;
template <class T, class T2> ostream &operator<<(ostream &o, pair<T, T2> p)
{
    o << "(" << p.first << ", " << p.second << ")"; 
    return o;
}

void solve()
{

}

signed main() 
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("log.txt", "w", stderr);
    #endif
    ios_base::sync_with_stdio(0);
	cin.tie(0); 
    int t;
    cin >> t;
    while (t--)
        solve();
}
