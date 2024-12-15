/**
 * Author: Vuong Nguyen
 * Date: 2019-04-11
 * Description: Builds suffix array for a string.
 * \texttt{sa[i]} is the starting index of the suffix which
 * is $i$'th in the sorted suffix array.
 * ("BANANA@" -> {6, 5, 3, 1, 0, 4, 2})
 * The returned vector is of size $n$, and \texttt{sa[0] = n}.
 * The \texttt{lcp} array contains longest common prefixes for
 * neighbouring strings in the suffix array:
 * \texttt{lcp[i] = lcp(sa[i], sa[i-1])}, \texttt{lcp[0] = 0}.
 * ("BANANA@" -> {0 0 1 3 0 0 2})
 * The input string must not contain any zero bytes.
 * Push back a dummny charater before call the funtions.
 * Time: O(n \log n)
 * Status: stress-tested
 */

vector <int> build_suffix_array(string &s, int lim = 256)
{
    int n = s.size();
    vector <int> sa(n);
    vector <int> prevSA(n), prevLabel(n), label(n), cnt(max(lim + 1, n), 0);
    REP (i, n) cnt[s[i]]++;
    FOR (i, 1, lim - 1) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; --i)
        sa[--cnt[s[i]]] = i;
    label[sa[0]] = 0;
    FOR (i, 1, n - 1)
        label[sa[i]] = (s[sa[i]] == s[sa[i - 1]]? label[sa[i - 1]]: label[sa[i - 1]] + 1); 
    for (int len = 1;; len *= 2)
    {
        REP (i, n) prevSA[i] = (sa[i] - len + n) % n;
        REP (i, n) prevLabel[i] = label[prevSA[i]];
        cnt.assign(n, 0);
        REP (i, n) cnt[prevLabel[i]]++;
        FOR (i, 1, n - 1) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; --i)
            sa[--cnt[prevLabel[i]]] = prevSA[i];
        swap(prevLabel, label);
        label[sa[0]] = 0;
        FOR (i, 1, n - 1)
        {
            pii cur = {prevLabel[sa[i]], prevLabel[(sa[i] + len) % n]};
            pii p = {prevLabel[sa[i - 1]], prevLabel[(sa[i - 1] + len) % n]};
            label[sa[i]] = (cur == p? label[sa[i - 1]]: label[sa[i - 1]] + 1);
        }
        if (label[sa[n - 1]] == n - 1)
            break; 
    }
    return sa;
}
 
vector <int> build_lcp(string &s, vector <int> &sa)
{
    int n = s.size(), rank[n];
    vector <int> lcp(n);
    REP (i, n) rank[sa[i]] = i;
    for (int i = 1, q = 0; i < n; ++i)
    {
        int pre = sa[rank[i] - 1];
        while (s[pre + q] == s[i + q]) ++q;
        lcp[rank[i]] = q;
        if (q > 0) --q;
    }
    return lcp;
}