/**
 * Author: Vuong Nguyen
 * License: CC0
 * Source: http://codeforces.com/blog/entry/60737
 * Description: Example solve for https://www.spoj.com/problems/COT2/ using mo algorithm on tree
 * Time: O(q \sqrt n)
 */
const int M = 1e5 + 5, SZ = 282;
int st[M], en[M], t, n, q;
bool flag[M];
int a[M], dep[M];
int up[M][20];
int cnt[M], res[M], cur = 0;
vector <int> adj[M];
vector <int> tour;
void add(int x)
{
	x = tour[x];
	// modify base on node id x
}

struct Query
{
	int l, r, id, lca;
};
void compress(){}
int find_kth_ancestor(int x, int k){}
int find_lca(int u, int v){}
void dfs(int x)
{
	flag[x] = 1;
	tour.push_back(x);
	st[x] = t++;
	for (auto it: adj[x])
	{
		if (!flag[it])
		{
			up[it][0] = x;
			dep[it] = dep[x] + 1;
			dfs(it);
		}
	}
	tour.push_back(x);
	en[x] = t++;
}

void moving(int l1, int r1, int l2, int r2)
{
	if (l2 < l1)
	{
		for (int i = l2; i < l1; ++i)
			add(i);
	}
	if (l2 > l1)
	{
		for (int i = l1; i < l2; ++i)
			add(i);
	}
	if (r2 > r1)
	{
		for (int i = r1 + 1; i <= r2; ++i)
			add(i);
	}
	if (r2 < r1)
	{
		for (int i = r2 + 1; i <= r1; ++i)
			add(i);
	}
}
signed main()
{
	// get input and compress data

	// find euler tour and init for lca
	vector <Query> m(q);
	for (int i = 0; i < q; ++i)
	{
		int u, v;
		cin >> u >> v;
		if (st[u] > st[v])
			swap(u, v);
		int l = find_lca(u, v);
		if (l == u || l == v)
		    m[i] = {st[u], st[v], i, 0};
		else
			m[i] = {en[u], st[v], i, l};
	}
	// implentment standard mo algorithm
}