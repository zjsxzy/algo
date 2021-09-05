/*
ID: frankzh1
TASK: milk6
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
const int MAXN = 100 + 10;
const int inf = 0x3f3f3f3f;
struct SAP
{
	int cap[MAXN][MAXN], flow[MAXN][MAXN], g[MAXN][MAXN];
	int n;
	int h[MAXN], vh[MAXN], source, sink;
	void init(int n)
	{
		this->n = n;
		memset(cap, 0, sizeof(cap));
		memset(g, 0, sizeof(g));
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
}sap;

int g[MAXN][MAXN];
struct Edge {
    int from, to, weight, idx;
    Edge(int from, int to, int weight, int idx) {
        this->from = from;
        this->to = to;
        this->weight = weight;
        this->idx = idx;
    }
    bool operator < (const Edge& p) {
        if (weight != p.weight) {
            return weight > p.weight;
        } else {
            return idx < p.idx;
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    sap.init(n);
    vector<Edge> edge;
    memset(g, 0, sizeof(g));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        sap.addCap(u, v, w);
        g[u][v] += w;
        edge.emplace_back(u, v, w, i + 1);
    }
    LL res = sap.solve(0, n - 1);
    sort(edge.begin(), edge.end());
    vector<int> cut;
    int max_flow = res;
    for (int i = 0; i < m; i++) {
        int u = edge[i].from, v = edge[i].to, w = edge[i].weight;
        // reset
        sap.init(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sap.cap[i][j] = g[i][j];
            }
        }
        // check edge i
        sap.cap[u][v] -= w;
        int min_cut = sap.solve(0, n - 1);
        if (min_cut + w == max_flow) {
            cut.emplace_back(edge[i].idx);
            max_flow = min_cut;
            g[u][v] -= w;
        }
    }
    cout << res << " " << cut.size() << endl;
    sort(cut.begin(), cut.end());
    for (int i = 0; i < cut.size(); i++) {
        cout << cut[i] << endl;
    }
}

int main() {
    freopen("milk6.in", "r", stdin);
    freopen("milk6.out", "w", stdout);
    solve();
    return 0;
}

