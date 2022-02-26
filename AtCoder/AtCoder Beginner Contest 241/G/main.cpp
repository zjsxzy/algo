#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

typedef int F;
#define inf (1 << 29)
#define maxV 2500
#define maxE 400000
struct Dinic {
	int V, E;
	F cap[maxE], flow[maxE];
	int to[maxE], prev[maxE];
	int level[maxV], used[maxV], last[maxV];

	void init(int n) {
		V = n; E = 0;
		for (int i = 0; i < V; i++) last[i] = -1;
	}

	void addCap(int x, int y, F f) {
		cap[E] = f; flow[E] = 0; to[E] = y; prev[E] = last[x]; last[x] = E; E++;
		cap[E] = 0; flow[E] = 0; to[E] = x; prev[E] = last[y]; last[y] = E; E++;
	}

	bool bfs(int s, int t) {
		for (int i = 0; i < V; i++)
			level[i] = -1;
		queue<int> q;
		q.push(s); level[s] = 0;
		while (!q.empty()) {
			int x = q.front(); q.pop();
			for (int i = last[x]; i != -1; i = prev[i])
				if (level[to[i]] == -1 && cap[i] > flow[i]) {
					q.push(to[i]);
					level[to[i]] = level[x] + 1;
				}
		}
		return (level[t] != -1);
	}

	F dfs(int v, int t, F f) {
		if (v == t) return f;
		for (int i = used[v]; i != -1; used[v] = i = prev[i])
			if (level[to[i]] > level[v] && cap[i] > flow[i]) {
				F tmp = dfs(to[i], t, min(f, cap[i] - flow[i]));
				if (tmp > 0) {
					flow[i] += tmp;
					flow[i ^ 1] -= tmp;
					return tmp;
				}
			}
		return 0;
	}

	F solve(int s, int t) {
		while (bfs(s, t)) {
			for (int i = 0; i < V; i++) used[i] = last[i];
			while (dfs(s, t, inf) != 0);
		}
		F ans = 0;
		for (int i = last[s]; i != -1; i = prev[i])
			ans += flow[i];
		return ans;
	}
}mf;

const int maxn = 55;
int n, m;
int A[maxn][maxn];
int win[maxn], lost[maxn];

bool check(int p) {
    int tot_match = n * (n - 1) / 2;
    int source = 0, sink = tot_match + n + 1;
    mf.init(sink + 1);
    int match_id = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            match_id++;
            mf.addCap(source, match_id, 1);
            //cout << i << " " << j << " " << match_id << " " << A[i][j] << endl;
            if (A[i][j] == 1) mf.addCap(match_id, tot_match + i, 1);
            else if (A[i][j] == -1) mf.addCap(match_id, tot_match + j, 1);
            else {
                mf.addCap(match_id, tot_match + i, 1);
                mf.addCap(match_id, tot_match + j, 1);
            }
        }
    }
    int rest = win[p] + (n - 1 - win[p] - lost[p]);
    for (int i = 1; i <= n; i++) {
        if (i == p) mf.addCap(tot_match + p, sink, rest);
        else mf.addCap(tot_match + i, sink, rest - 1);
    }
    int res = mf.solve(source, sink);
    return res == tot_match;
}

void solve() {
    cin >> n >> m;
    memset(A, 0, sizeof(A));
    for (int i = 0; i < m; i++) {
        int w, l;
        cin >> w >> l;
        A[w][l] = 1;
        A[l][w] = -1;
        win[w]++;
        lost[l]++;
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (check(i)) {
            ans.push_back(i);
        }
    }
    for (auto& x: ans) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

