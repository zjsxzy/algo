/*
 * Author : Yang Zhang
 */
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
typedef long long LL;

const int maxn = 200005;
struct BinaryIndexTree {
	int N;
	int C[2 * maxn];
	
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
	
	int sum(int x) {
		int ret = 0;
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
	lcaת��Ϊrmq����
	ע��: 
		1.maxnΪ���ڵ���, ST�������F��bufҪ����Ϊ2*maxn!!!!!
		2.ST��Ϊ1��ʼ��������ȻΪ0��ʼ!
		3.F��ŷ������,rmq���������,Pĳ����ŷ�������е�һ�γ��ֵ�λ��
*/
struct LCA2RMQ {
	int n;							//�ڵ����
	Nod buf[2*maxn]; int len; int E[maxn];	//Tree	��Դ
	int V[2*maxn], route[maxn];				//·����Ȩ������ĳ���·����
	bool vis[maxn];						//0û�з��ʣ�Ҽ���ڷ���
	int endP[maxn];
	ST st;							//Spare-Table...
	int F[2*maxn], P[maxn], cnt;	//��������,cntΪ������,levΪdfsʱ����(���ٵݹ�ջ��С)
	
	void init(int n) {
		th(n);
		len = 0;
		memset(E, 255, sizeof(E));
	}
	
	void addEdge(int a, int b, int v) {
		buf[len].init(b, E[a]); V[len] = v; E[a] = len ++;
		buf[len].init(a, E[b]);	V[len] = v;	E[b] = len ++;
	}
	
	int query(int a, int b) {				//���������ڵ㣬��������lca�ڵ���
		return F[st.query(P[a], P[b])];
	}
	
	//1.���ݹ�桿
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
	
	//2.���ǵݹ�桿
	/*void solve(int root) {
		static Nod stk[maxn];
		memset(vis, 0, sizeof(vis));
		
		stk[0].init(root, E[root]);
		int len = Ҽ;
		int lev = 0;
		cnt = 0;
		route[root] = 0;										//update route!
		
		while(Ҽ) {
			Nod & cur = stk[len-Ҽ];
//here, b means current Nod, nxt means nxt's pointer(as buf.nxt)!
			if(false == vis[cur.b]) {
				vis[cur.b] = Ҽ;
				F[++ cnt] = cur.b;
				rmq[cnt] = lev;
				P[cur.b] = cnt;
			} else if(cur.nxt == -Ҽ) {
				if(--len == 0)	break;
				F[++ cnt] = stk[len-Ҽ].b;
				rmq[cnt] = -- lev;
			} else {
				int & i = cur.nxt;
				if(!vis[buf[i].b]) {
					route[buf[i].b] = route[cur.b] + V[i];		
//update route!
					lev ++;
					stk[len ++].init(buf[i].b, E[buf[i].b]);
				}
				i = buf[i].nxt;
			}
		}
		st.init(2 * n - 1);
		}*/
} lca;

vector<pair<int, int> > edge;
vector<int> cost;
int n, q, s;
int main() {
	freopen("in.txt", "r", stdin);
	scanf("%d%d%d", &n, &q, &s);
	lca.init(n);
	for (int i = 1; i < n; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		lca.addEdge(u, v, w);
		edge.PB(MP(u, v));
		cost.PB(w);
	}
	lca.solve(s);
	T.init(2 * n);
	while (q--) {
		int k;
		scanf("%d", &k);
		if (k == 0) {
			int id;
			scanf("%d", &id);
			int anc = lca.query(id, s);
			int dist = lca.route[id] + lca.route[s] - 2 * lca.route[anc];
			int tmp = T.sum(lca.P[id]) + T.sum(lca.P[s]) - 2 * T.sum(lca.P[anc]);
			printf("%d\n", dist + tmp);
			s = id;
		} else {
			int id, weight;
			scanf("%d%d", &id, &weight);
			id--;
			int u = edge[id].first, v = edge[id].second, w = cost[id];
			int del = weight - w;
			if (lca.P[v] < lca.P[u]) {
				T.add(lca.P[u], del);
				T.add(lca.endP[u] + 1, -del);
			} else {
				T.add(lca.P[v], del);
				T.add(lca.endP[v] + 1, -del);
			}
		}
	}
	return 0;
}
