/*
ID: frankzh1
TASK: schlnet
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 105;
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
		adj[u].PB(v);
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
			size++;
			int v;
			do {
				v = S.top();
				S.pop();
				id[v] = size;
				vis[v] = false;
			} while (u != v);
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

void solve() {
    int n;
    cin >> n;
    g.init(n);
    vector<pair<int, int>> edges;
    for (int i = 0; i < n; i++) {
        int x;
        while (cin >> x) {
            if (x == 0) break;
            x--;
            edges.emplace_back(i, x);
            g.addEdge(i, x);
        }
    }
    g.SCC();
    vector<int> indeg(g.size + 1), outdeg(g.size + 1);
    for (auto &p: edges) {
        if (g.id[p.first] != g.id[p.second]) {
            //cout << g.id[p.first] << "->" << g.id[p.second] << endl;
            outdeg[g.id[p.first]]++;
            indeg[g.id[p.second]]++;
        }
    }
    if (g.size == 1) {
        cout << 1 << endl << 0 << endl;
        return;
    }
    int sum_in = 0, sum_out = 0;
    for (int i = 1; i <= g.size; i++) {
        if (indeg[i] == 0) sum_in++;
        if (outdeg[i] == 0) sum_out++;
    }
    cout << sum_in << endl;
    cout << max(sum_in, sum_out) << endl;
}

int main() {
    freopen("schlnet.in", "r", stdin);
    freopen("schlnet.out", "w", stdout);
    solve();
    return 0;
}

