/**
 * Author: Vuong Nguyen
 * Description: class for finding max matching of a bipartite graph (index start from 0)
 * Usage: Matching mat(max(n, m))
 * For each edge: mat.addEdge(u, v, c)
 * call mat.match() return max match size.
 * then matchL[i] is the id of right node matching with i left node
 * (-1 means i left node is not match)
 * Status: tested on VNOJ - FMATCH, VNOJ - MATCH1.
 * Time: O(nm) , ~0.5s with n = 50000 and m = 150000.
 */
struct Matching 
{
    vector <vector <int>> adj;
    vector <int> matchL, matchR, t;
    int n, curT;
    Matching(int _n)
    {
        n = _n, curT = 0;
        adj.resize(n), matchL.resize(n, -1), matchR.resize(n, -1), t.resize(n, 0);
    }
    int init()
    {
        int initSz = 0;
        for (int l = 0; l < n; ++l)
        {
            for (auto r: adj[l])
            {
                if (matchR[r] == -1)
                {
                    assign(l, r);
                    initSz++;
                    break;
                }
            }
        }
        return initSz;
    }
    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
    }
    void assign(int u, int v)
    {
        matchL[u] = v, matchR[v] = u;
    }
    bool dfs(int l)
    {
        t[l] = curT;
        for (auto r: adj[l])
        {
            if (matchR[r] == -1)
            {
                assign(l, r);
                return true;
            }
        }
        for (auto r: adj[l])
        {
            if (t[matchR[r]] < curT && dfs(matchR[r]))
            {
                assign(l, r);
                return true;
            }
        }
        return false;
    }
    int match()
    {
        int res = init();
        while (1)
        {
            curT++;
            bool havNewMatch = 0;
            for (int i = 0; i < n; ++i)
            {
                if (matchL[i] == -1 && dfs(i))
                    havNewMatch = 1, res++;
            }
            if (!havNewMatch)
                return res;
        }
    }
};