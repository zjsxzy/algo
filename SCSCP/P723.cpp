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

int calc(vector<vector<int>>& adj, vector<int>& cnt, int st) {
    int n = adj.size();
    vector<int> color(n);
    function<void(int)> dfs = [&](int u) {
        color[u] = 1;
        for (auto v: adj[u]) {
            if (!color[v]) {
                dfs(v);
            }
        }
    };
    dfs(st);
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
    int res = 0;
    for (auto v: adj[st]) {
        res = max(res, dp[v]);
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    g.init(n);
    vector<pair<int, int>> eds;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g.addEdge(u, v);
        eds.emplace_back(u, v);
    }
    g.SCC();
    int sz = g.size;
    vector<int> cnt(sz);
    for (int i = 0; i < n; i++) {
        cnt[g.id[i]]++;
    }
    vector<vector<int>> adj(sz);
    for (int i = 0; i < m; i++) {
        if (g.id[eds[i].first] != g.id[eds[i].second]) {
            adj[g.id[eds[i].first]].push_back(g.id[eds[i].second]);
        }
    }
    int res1 = calc(adj, cnt, g.id[0]);
    adj.assign(n, {});
    for (int i = 0; i < m; i++) {
        if (g.id[eds[i].first] != g.id[eds[i].second]) {
            adj[g.id[eds[i].second]].push_back(g.id[eds[i].first]);
        }
    }
    int res2 = calc(adj, cnt, g.id[0]);
    cout << max(cnt[g.id[0]], max(res1, res2)) << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}