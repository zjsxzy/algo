#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 200005;
const int MAXM = 400005;
struct DisJointSet{
	int rank[MAXN], parent[MAXN];

	void init(int n) {
		for (int i = 0; i < n; i++) {
			rank[i] = 0;
			parent[i] = i;
		}
	}

	int Find(int x) {
		if (parent[x] == x) return x;
		return parent[x] = Find(parent[x]);
	}

	void Union(int x, int y) {
		x = Find(x);
		y = Find(y);

		if (x == y) return;

		if (rank[x] >= rank[y]) {
			parent[y] = x;
			if (rank[x] == rank[y])
				rank[x]++;
		}
		else {
			parent[x] = y;
		}
	}
}uf;


struct Edge {
    int from, to, w, ans, idx;
    bool operator < (Edge const& other) const {
        return make_pair(w, to) < make_pair(other.w, other.to);
    }
};
Edge edges[MAXM];

bool cmp(const Edge& a, const Edge& b) {
    return a.idx < b.idx;
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].w;
        edges[i].idx = m + q;
    }
    for (int i = m; i < m + q; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].w;
        edges[i].idx = i - m;
    }
    sort(edges, edges + m + q);
    uf.init(n + 1);
    int mst = 0;
    for (int i = 0; i < m + q; i++) {
        int u = edges[i].from, v = edges[i].to;
        // cout << edges[i].from << " " << edges[i].to << " " << edges[i].w << endl;
        if (edges[i].idx == m + q) {
            if (uf.Find(u) != uf.Find(v)) {
                mst += edges[i].w;
                uf.Union(u, v);
            }
        } else {
            if (uf.Find(u) != uf.Find(v)) {
                edges[i].ans = 1;
            } else {
                edges[i].ans = 0;
            }
        }
    }
    sort(edges, edges + m + q, cmp);
    for (int i = 0; i < q; i++) {
        if (edges[i].ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

