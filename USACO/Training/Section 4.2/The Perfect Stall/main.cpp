/*
ID: frankzh1
TASK: stall4
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 205;
int mk[MAXN], cx[MAXN], cy[MAXN];
vector<int> adj[MAXN];
int n1, n2;

void addEdge(int u, int v) {
	adj[u].PB(v);
	//cout << u << "->" << v << endl;
}

int path(int u) {
	for (int i = 0, v; i < adj[u].size(); i++) {
		if (!mk[v = adj[u][i]]) {
			mk[v] = 1;
			if (cy[v] == -1 || path(cy[v])) {
				cx[u] = v;
				cy[v] = u;
				return 1;
			}
		}
	}
	return 0;
}

int MaxMatch() {
	memset(cx, -1, sizeof(cx));
	memset(cy, -1, sizeof(cy));
	int ret = 0;
	for (int i = 0; i < n1; i++) {
		if (cx[i] == -1) {
			memset(mk, 0, sizeof(mk));
			ret += path(i);
		}
	}
	return ret;
}

void solve() {
    cin >> n1 >> n2;
    for (int i = 0; i < n1; i++) {
        int s;
        cin >> s;
        for (int j = 0; j < s; j++) {
            int x;
            cin >> x;
            x--;
            addEdge(i, x);
        }
    }
    int res = MaxMatch();
    cout << res << endl;
}

int main() {
    freopen("stall4.in", "r", stdin);
    freopen("stall4.out", "w", stdout);
    solve();
    return 0;
}

