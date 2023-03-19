#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 200005;
struct BinaryIndexTree {
	int N;
	LL C[2 * maxn];
	
	void init(int N) {
		this->N = N;
		memset(C, 0, sizeof(C));
	}
	
	int lowbit(int x) {
		return x & (-x);
	}
	
	void add(int x, int num) {
		for (int i = x; i <= N; i += lowbit(i))
			C[i] += num;
	}
	
	LL sum(int x) {
		LL ret = 0;
		for (int i = x; i > 0; i -= lowbit(i))
			ret += C[i];
		return ret;
	}
}T;

#define th(x) this->x = x
int rmq[2 * maxn];
struct ST {
	int mm[2 * maxn];
	int best[20][2 * maxn];

	void init(int n) {
		int i, j, a, b;
		mm[0] = -1;
		for (i = 1; i <= n; i++) {
			mm[i] = ((i & (i - 1)) == 0 ? mm[i - 1] + 1 : mm[i - 1]);
			best[0][i] = i;
		}
		for (i = 1; i <= mm[n]; i++) {
			for (j = 1; j <= n + 1 - (1 << i); j++) {
				a = best[i - 1][j];
				b = best[i - 1][j + (1 << (i - 1))];
				best[i][j] = rmq[a] < rmq[b] ? a : b;
			}
		}
	}

	int query(int a, int b) {
		if (a >  b) swap(a, b);
		int t;
		t = mm[b - a + 1];
		a = best[t][a];
		b = best[t][b - (1 << t) + 1];
		return rmq[a] < rmq[b] ? a : b;
	}
};
struct Nod {
	int b, nxt;
	void init(int b, int nxt) {
		th(b); th(nxt);
	}
};
/**
	lca转化为rmq问题
	注意: 
		1.maxn为最大节点数, ST的数组和F、buf要设置为2*maxn!!!!!
		2.ST类为1开始，此类依然为0开始!
		3.F是欧拉序列,rmq是深度序列,P某点在欧拉序列中第一次出现的位置
*/
struct LCA2RMQ {
	int n;							//节点个数
	Nod buf[2*maxn]; int len; int E[maxn];	//Tree	资源
	LL V[2*maxn], route[maxn];				//路径的权，根到某点的路径和
	bool vis[maxn];						//0没有访问，壹正在访问
	int endP[maxn];
	ST st;							//Spare-Table...
	int F[2*maxn], P[maxn], cnt;	//介绍如上,cnt为计数器,lev为dfs时层数(减少递归栈大小)
	
	void init(int n) {
		th(n);
		len = 0;
		memset(E, 255, sizeof(E));
	}
	
	void addEdge(int a, int b, int v) {
		buf[len].init(b, E[a]); V[len] = v; E[a] = len ++;
		buf[len].init(a, E[b]);	V[len] = v;	E[b] = len ++;
	}
	
	int query(int a, int b) {				//传入两个节点，返回他们lca节点编号
		return F[st.query(P[a], P[b])];
	}
	
	//1.【递归版】
	void dfs(int a, int lev) {
		vis[a] = 1;		
		++cnt;
		F[cnt] = a;
		rmq[cnt] = lev;
		P[a] = cnt;
		for(int i = E[a]; i != -1; i = buf[i].nxt) {
			if(vis[buf[i].b]) continue;
			route[buf[i].b] = route[a] + V[i];
			dfs(buf[i].b, lev + 1);
			++cnt;
			F[cnt] = a;
			rmq[cnt] = lev;
		}
		endP[a] = cnt;
	}
	void solve(int root) {
		memset(vis, 0, sizeof(vis));
		route[root] = cnt = 0;
		dfs(root, 0);
		st.init(2 * n - 1);
	}

} lca;

void solve() {
    vector<pair<int, int>> edge;
    vector<int> cost;
    int n, q;
    cin >> n;
	lca.init(n);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        lca.addEdge(u, v, w);
        edge.push_back({u, v});
        cost.push_back(w);
    }
    cin >> q;
    lca.solve(0);
    T.init(2 * n);
    while (q--) {
        int k;
        cin >> k;
        if (k == 2) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            int anc = lca.query(u, v);
            LL dist = lca.route[u] + lca.route[v] - 2 * lca.route[anc];
            LL tmp = T.sum(lca.P[u]) + T.sum(lca.P[v]) - 2 * T.sum(lca.P[anc]);
            cout << dist + tmp << endl;
        } else {
            int id, weight;
            cin >> id >> weight;
            id--;
            int u = edge[id].first, v = edge[id].second, w = cost[id];
            int del = weight - w;
            cost[id] = weight;
            if (lca.P[v] < lca.P[u]) {
                T.add(lca.P[u], del);
                T.add(lca.endP[u] + 1, -del);
            } else {
                T.add(lca.P[v], del);
                T.add(lca.endP[v] + 1, -del);
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}