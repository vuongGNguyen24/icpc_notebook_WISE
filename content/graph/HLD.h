/**
 * Author: Vuong Nguyen
 * Date: 2024-05-29
 * License: CC0
 * Description:  Decomposes a tree into vertex disjoint heavy paths and light
 * edges such that the path from any leaf to the root contains at most $\log n$ light edges. (0 index base)
 * Usage: implenting segment tree.
 *  after push edge in adj[], call dfs(root) and hld(root).
 *  For query path u -> v call query(u, v) (jump to chain containing lca(u, v))
 *  For update node u update position pos[u] in segment tree
 * Time: O(\log ^ 2 n) for each path queries.
 */
const int M = 1e5 + 5;
int head[M], pos[M], par[M], sz[M], dep[M];
vector <int> adj[M];
int curId, n;
// implenting segment tree
int get(int l, int r)
{
    return 0;
}

void update(int l, int r, int val)
{

}
// end implentment segment tree

void dfs(int x, int pre = -1)
{
    par[x] = pre;
    sz[x] = 1;
    for (auto it: adj[x])
    {
        if (it != pre)
        {
            dep[it] = dep[x] + 1;
            dfs(it, x);
            sz[x] += sz[it];
        }
    }
}

void hld(int x, int chainHead = 1, int pre = -1)
{
    head[x] = chainHead, pos[x] = curId++;
    int nxt = -1;
    for (auto it: adj[x])
    {
        if (it == pre)
            continue;
        if (nxt == -1 || sz[nxt] < sz[it])
            nxt = it;
    }
    if (nxt == -1)
        return;
    hld(nxt, chainHead, x);
    for (auto it: adj[x])
    {
        if (it != pre && it != nxt)
            hld(it, it, x);
    }
}

int query(int u, int v)
{
    int res = 0;
    while (head[u] != head[v])
    {
        if (dep[head[u]] < dep[head[v]])
            swap(u, v);
        res += get(pos[head[u]], pos[u]); 
        u = par[head[u]];
    }
    if (dep[u] > dep[v])
        swap(u, v);
    res += get(pos[u], pos[v]);
    return res;
}
// useful funtion for query path
int lca(int u, int v)
{
    while (head[u] != head[v])
    {
        if (dep[head[u]] < dep[head[v]])
            swap(u, v);
        u = par[head[u]];
    }
    return (dep[u] < dep[v]? u: v);
}