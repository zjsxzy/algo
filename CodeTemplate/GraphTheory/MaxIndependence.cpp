//求最大独立集及其方案
struct SAP {
    int cap[MAXN][MAXN], flow[MAXN][MAXN], g[MAXN][MAXN];
    int n;
    int h[MAXN], vh[MAXN], source, sink;
    int mk[MAXN];

    void init(int n) {
        this->n = n;
        memset(cap, 0, sizeof(cap));
        memset(g, 0, sizeof(g));
        memset(mk, 0, sizeof(mk));
    }
    void addCap(int i, int j, int val) {
        cap[i][j] = val;
        g[i][j] = 1;
    }
    int sap(const int idx, const int maxCap) {
        if (idx == sink)
            return maxCap;
        int l = maxCap, d, minH = n;
        for (int i = 0; i < n; i++) {
            if (cap[idx][i] - flow[idx][i] > 0) {
                if (h[idx] == h[i] + 1) {
                    d = sap(i, min(l, cap[idx][i] - flow[idx][i]));
                    flow[idx][i] += d;
                    flow[i][idx] -= d;
                    l -= d;
                    if (h[source] == n || l == 0) return maxCap - l;
                }
                minH = min(minH, h[i] + 1);
            }
        }
        if (l == maxCap) {
            vh[h[idx]]--;
            vh[minH]++;
            if (vh[h[idx]] == 0)
                h[source] = n;
            h[idx] = minH;
        }
        return maxCap - l;
    }
    int solve(int source, int sink) {
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

	void dfs(int u) {
		mk[u] = 1; 
		for (int i = 0; i < n; i++) {
			if (!mk[i] && cap[u][i] - flow[u][i] > 0) dfs(i);
		}
	}

	bool ch[MAXN];
    void output(int m) {
		memset(mk, 0, sizeof(mk));
		memset(ch, 0, sizeof(ch));
		dfs(source);
		vector<int> ans;
		for (int i = 1; i < n - 1; i++) {
			if (g[source][i] && mk[source] != mk[i]) {
				ch[i] = 1;
			}
			if (g[i][sink] && mk[i] != mk[sink]) {
				ch[i - m] = 1;
			}
		}
		for (int i = 1; i <= m; i++)
			if (!ch[i]) ans.PB(i);
		for (int i = 0; i < ans.size(); i++)
			printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
    }
}sap;
