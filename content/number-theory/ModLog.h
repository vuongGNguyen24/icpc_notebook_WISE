/**
 * Author: Vuong Nguyen
 * Description: funtion return min $n \geq 0$ such that $a^n = b$ (mod m), return -1 if it doesn't have any integers. 
 * Time: O(\sqrt m)
 * Status: tested on https://codeforces.com/gym/535734/problem/L
 */
#include "ModInt.h"
int log_mod(int a, int b)
{
    if (a % MOD == 0)
        return b == 0? 0: -1;
    int m = sqrt(MOD);
    unordered_map<int, int> st;
    for (int cur = 0, a_m = pow_mod(a, m), val = 1; cur < MOD - 1; cur += m)
    {
        st[val] = st.find(val) != st.end()? min(cur, st[val]): cur;
        val = mul(val, a_m);
    }
    int res = MOD;
    for (int y = 0, invA = inv(a), curY = 1; y < m; ++y, curY = mul(invA, curY))
    {
        int tmp = mul(b, curY);
        if (st.find(tmp) != st.end())
            res = min(res, st[tmp] + y);
    }
    return res == MOD? -1: res;
}