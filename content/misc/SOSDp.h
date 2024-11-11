/**
 * Author: Vuong Nguyen
 * Description: 2 functions involve in sum over subset dp
 * Time: O(m \times 2^m) m is bit size.
 * Status: somewhat tested
 */
vector <int> sum_over_super_set(vector <int> a, int m)
{
    // a = {1, 4, 2, 3} then dp = {10, 7, 5, 3}.
    auto dp = a;
    for(int i = 0; i < m; i++) {
        for(int mask = (1 << m) - 1; mask >= 0; mask--) {
            if(mask >> i & 1)
                dp[mask ^ (1 << i)] += dp[mask];
        }
    }
    return dp;
}

vector <int> sum_over_subset(vector <int> a, int m)
{
    // a = {1, 4, 2, 3} then dp = {1, 5, 3, 10}.
    auto dp = a;
    for(int i = 0; i < m; i++) {
        for(int mask = 0; mask < (1 << m); ++mask) {
            if(mask >> i & 1)
                dp[mask] += dp[mask ^ (1 << i)];
        }
    }
    return dp;
}