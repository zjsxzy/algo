#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 100005;
struct Graph {
	int n, size, depth;
	vector<int> adj[MAXN];
	int low[MAXN], dfn[MAXN], id[MAXN];
	bool vis[MAXN];
	stack<int> S;

	void init(int n) {
		this->n = n;
		for (int i = 0; i <= n; i++)
			adj[i].clear();
		memset(id, 0, sizeof(id));
		memset(vis, 0, sizeof(vis));
		while (!S.empty()) S.pop();
	}

	void addEdge(int u, int v) {
		adj[u].push_back(v);
	}

	void Tarjan(int u) {
		dfn[u] = low[u] = depth++;
		S.push(u);
		vis[u] = true;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			if (dfn[v] == -1) {
				Tarjan(v);
				low[u] = min(low[u], low[v]);
			} else if (vis[v]) {
				low[u] = min(low[u], dfn[v]);
			}
		}
		if (low[u] == dfn[u]) {
			int v;
			do {
				v = S.top();
				S.pop();
				id[v] = size;
				vis[v] = false;
			} while (u != v);
			size++;
		}
	}

	void SCC() {
		memset(dfn, -1, sizeof(dfn));
		size = 0;
		depth = 1;
		for (int i = 0; i < n; i++)
			if (dfn[i] == -1) Tarjan(i);
	}

}g;

vector<int> topo(vector<vector<int>>& adj, vector<int>& color, vector<int>& cnt) {
    int n = adj.size();
    vector<int> deg(n);
    vector<vector<int>> g(n);
    for (int u = 0; u < n; u++) {
        if (!color[u]) continue;
        for (auto v: adj[u]) {
            if (!color[v]) continue;
            g[u].push_back(v);
            deg[v]++;
        }
    }
    queue<int> q;
    vector<int> dp(n);
    for (int u = 0; u < n; u++) {
        if (deg[u] == 0) {
            q.push(u);
            dp[u] = cnt[u];
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v: g[u]) {
            dp[v] = max(dp[v], dp[u] + cnt[v]);
            deg[v]--;
            if (deg[v] == 0) q.push(v);
        }
    }
    return dp;
}

void dfs(vector<vector<int>>& adj, vector<int>& vst, int u) {
    vst[u] = 1;
    for (auto v: adj[u]) {
        if (!vst[v]) {
            dfs(adj, vst, v);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    g.init(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g.addEdge(u, v);
    }
    g.SCC();
    int sz = g.size;
    vector<int> cnt(sz);
    for (int i = 0; i < n; i++) {
        cnt[g.id[i]]++;
    }
    vector<vector<int>> adj(sz), radj(sz);
    for (int u = 0; u < n; u++) {
        for (auto v: g.adj[u]) {
            if (g.id[u] == g.id[v]) continue;
            adj[g.id[u]].push_back(g.id[v]);
            radj[g.id[v]].push_back(g.id[u]);
        }
    }
    vector<int> color(sz), rcolor(sz);
    dfs(adj, color, g.id[0]);
    dfs(radj, rcolor, g.id[0]);
    vector<int> f = topo(adj, color, cnt);
    vector<int> rf = topo(radj, rcolor, cnt);
    int res = cnt[g.id[0]];
    for (int u = 0; u < sz; u++) {
        if (rcolor[u]) {
            for (auto v: adj[u]) {
                if (color[v]) {
                    res = max(res, rf[u] + f[v] - cnt[g.id[0]]);
                }
            }
        }
    }
    cout << res << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}