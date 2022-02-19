#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

/*
* Adjacency matrix
*/
const int MAXN = 200 + 10;
const LL inf = 1LL << 50;
struct SAP
{
	LL cap[MAXN][MAXN], flow[MAXN][MAXN], g[MAXN][MAXN];
	int n;
	LL h[MAXN], vh[MAXN];
    int source, sink;
	int mk[MAXN];
	void init(int n)
	{
		this->n = n;
		memset(cap, 0, sizeof(cap));
		memset(g, 0, sizeof(g));
		memset(mk, 0, sizeof(mk));
	}
	void addCap(int i, int j, LL val)
	{
		cap[i][j] += val;
		g[i][j] = 1;
	}
	LL sap(const int idx, const LL maxCap)
	{
		if (idx == sink)
			return maxCap;
		LL l = maxCap, d, minH = n;
		for (int i = 0; i < n; i++)
		{
			if (cap[idx][i] - flow[idx][i] > 0)
			{
				if (h[idx] == h[i] + 1)
				{
					d = sap(i, min(l, cap[idx][i] - flow[idx][i]));
					flow[idx][i] += d;
					flow[i][idx] -= d;
					l -= d;
					if (h[source] == n || l == 0) return maxCap - l;
				}
				minH = min(minH, h[i] + 1);
			}
		}
		if (l == maxCap)
		{
			vh[h[idx]]--;
			vh[minH]++;
			if (vh[h[idx]] == 0)
				h[source] = n;
			h[idx] = minH;
		}
		return maxCap - l;
	}
	LL solve(int source, int sink)
	{
		if (source == sink) return inf;
		this->sink = sink;
		this->source = source;
		memset(flow, 0, sizeof(flow));
		memset(h, 0, sizeof(h));
		memset(vh, 0, sizeof(vh));
		LL ans = 0;
		while (h[source] != n)
			ans += sap(source, inf);
		return ans;
	}
	void dfs(int u)
	{
		mk[u] = 1;
		for (int i = 0; i < n; i++)
		{
			if (!mk[i] && cap[u][i] - flow[u][i] > 0) dfs(i);
		}
	}
	void output(int nodes)
	{
        vector<int> ans;
		for (int i = 1; i < nodes - 1; i++) {
            int j = i + nodes;
			if (g[i][j] && cap[i][j] - flow[i][j] == 0 && mk[i] != mk[j]) {
                ans.push_back(i + 1);
            }
        }
        cout << ans.size() << endl;
        for (auto x: ans) {
            cout << x << " ";
        }
        cout << endl;
	}
}sap;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    sap.init(n * 2);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        sap.addCap(a + n, b, inf);
        sap.addCap(b + n, a, inf);
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        if (i == 0 || i == n - 1) sap.addCap(i, n + i, inf);
        else sap.addCap(i, n + i, c[i]);
    }
    LL res = sap.solve(0, 2 * n - 1);
    cout << res << endl;
    sap.dfs(0);
    sap.output(n);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

