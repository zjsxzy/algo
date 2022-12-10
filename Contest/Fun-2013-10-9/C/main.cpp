#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

const int MAXN = 200 + 10;
const int inf = 0x3f3f3f3f;
int n;
int w[MAXN][MAXN];
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

// Ural 1533
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &w[i][j]);
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				w[i][j] |= w[i][k] & w[k][j];
			}
		}
	}

	sap.init(2 * n + 2);
	int source = 0, sink = 2 * n + 1;
	for (int i = 1; i <= n; i++) {
		sap.addCap(source, i, 1);
		for (int j = 1; j <= n; j++) {
			if (i != j && w[i][j]) {
				sap.addCap(i, j + n, inf);
			}
		}
		sap.addCap(i + n, sink, 1);
	}
	int res = sap.solve(source, sink);
	printf("%d\n", n - res);
	sap.output(n);
	return 0;
}
