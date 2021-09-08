/*
ID: frankzh1
TASK: telecow
LANG: C++
 */
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
const int inf = 0x3f3f3f3f;
struct SAP
{
	int cap[MAXN][MAXN], flow[MAXN][MAXN], g[MAXN][MAXN];
	int n;
	int h[MAXN], vh[MAXN], source, sink;
	int mk[MAXN];
	void init(int n)
	{
		this->n = n;
		memset(cap, 0, sizeof(cap));
		memset(g, 0, sizeof(g));
		memset(mk, 0, sizeof(mk));
	}
	void addCap(int i, int j, int val)
	{
		cap[i][j] += val;
		g[i][j] = 1;
	}
	int sap(const int idx, const int maxCap)
	{
		if (idx == sink)
			return maxCap;
		int l = maxCap, d, minH = n;
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
	int solve(int source, int sink)
	{
		if (source == sink) return inf;
		this->sink = sink;
		this->source = source;
		memset(flow, 0, sizeof(flow));
		memset(h, 0, sizeof(h));
		memset(vh, 0, sizeof(vh));
		int ans = 0;
		while (h[source] != n)
			ans += sap(source, inf);
		return ans;
	}
};

int g[MAXN][MAXN];

void solve() {
    int n, m, c1, c2;
    cin >> n >> m >> c1 >> c2;
    c1--; c2--;
    SAP sap;
    sap.init(n * 2);
    for (int i = 0; i < n; i++) {
        if (i == c1 || i == c2) sap.addCap(i, i + n, inf);
        else sap.addCap(i, i + n, 1);
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        sap.addCap(u + n, v, inf);
        sap.addCap(v + n, u, inf);
    }
    int res = sap.solve(c1, c2 + n);
    cout << res << endl;
    vector<int> ans;

    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            g[i][j] = sap.cap[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == c1 || i == c2) continue;
        // reset
        sap.init(n * 2);
        for (int i = 0; i < 2 * n; i++) {
            for (int j = 0; j < 2 * n; j++) {
                sap.cap[i][j] = g[i][j];
            }
        }
        // check vertex i
        sap.cap[i][i + n] = 0;
        int min_cut = sap.solve(c1, c2 + n);
        // cout << i + 1 << " " << min_cut << endl;
        if (min_cut + 1 == res) {
            ans.emplace_back(i);
            res = min_cut;
            g[i][i + n] = 0;
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1;
        if (i == ans.size() - 1) cout << endl;
        else cout << " ";
    }
}

int main() {
    freopen("telecow.in", "r", stdin);
    freopen("telecow.out", "w", stdout);
    solve();
    return 0;
}

