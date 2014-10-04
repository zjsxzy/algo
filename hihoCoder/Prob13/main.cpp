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
#include <cassert>
#include <climits>
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

#define maxn 1005
#define th(x) this->x = x
int rmq[2*maxn];
struct ST {
	int mm[2*maxn];
	int best[20][2*maxn];
	void init(int n) {
		int i,j,a,b;
		mm[0]=-1;
		for(i=1; i<=n; i++) {
			mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
			best[0][i]=i;
		}
		for(i=1; i<=mm[n]; i++) {
			for(j=1; j<=n+1-(1<<i); j++) {
				a=best[i-1][j];
				b=best[i-1][j+(1<<(i-1))];
				best[i][j]=rmq[a] < rmq[b]?a:b;
			}
		}
	}
	int query(int a, int b) {
		if(a > b)	swap(a, b);
		int t;
		t=mm[b-a+1];
		a=best[t][a];
		b=best[t][b-(1<<t)+1];
		return rmq[a] < rmq[b] ? a : b;
	}
};
//下面是LCA2RMQ开始
struct Nod {
	int b, nxt;
	void init(int b, int nxt) {
		th(b);	th(nxt);
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
	Nod buf[2*maxn];	int len;	int E[maxn];	//Tree	资源
	int V[2*maxn], route[maxn];				//路径的权，根到某点的路径和
	char vis[maxn];						//0没有访问，1正在访问
	
	ST st;							//Spare-Table...
	int F[2*maxn], P[maxn], cnt;	//介绍如上,cnt为计数器,lev为dfs时层数(减少递归栈大小)
	
	void init(int n) {
		th(n);
		len = 0;
		memset(E, 255, sizeof(E));
	}
	void addEdge(int a, int b, int v) {
		buf[len].init(b, E[a]);		V[len] = v;		E[a] = len ++;
		//buf[len].init(a, E[b]);		V[len] = v;		E[b] = len ++;
	}
	int query(int a, int b) {				//传入两个节点，返回他们lca节点编号
		return F[st.query(P[a], P[b])];
	}
	//1.【递归版】
	void dfs(int a, int lev) {
		vis[a] = 1;
		
		++ cnt;
		F[cnt] = a;
		rmq[cnt] = lev;
		P[a] = cnt;
		for(int i = E[a]; i != -1; i = buf[i].nxt) {
			if(vis[buf[i].b])	continue;
			route[buf[i].b] = route[a] + V[i];
			dfs(buf[i].b, lev+1);
			++ cnt;
			F[cnt] = a;
			rmq[cnt] = lev;
		}
	}
	void solve(int root) {
		memset(vis, 0, sizeof(vis));
		route[root] = cnt = 0;
		dfs(root, 0);
		st.init(2*n-1);
	}
	
	//2.【非递归版】
/*	void solve(int root) {
		static Nod stk[maxn];
		memset(vis, 0, sizeof(vis));
		
		stk[0].init(root, E[root]);
		int len = 1;
		int lev = 0;
		cnt = 0;
		route[root] = 0;										//update route!
		
		while(1) {
			Nod & cur = stk[len-1];
//here, b means current Nod, nxt means nxt's pointer(as buf.nxt)!
			if(false == vis[cur.b]) {
				vis[cur.b] = 1;
				F[++ cnt] = cur.b;
				rmq[cnt] = lev;
				P[cur.b] = cnt;
			} else if(cur.nxt == -1) {
				if(--len == 0)	break;
				F[++ cnt] = stk[len-1].b;
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
		st.init(2*n-1);
	}*/
} lca;
map<string, int> idx;
map<int, string> name;
int deg[maxn * 2];
int person;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n, m;
	scanf("%d", &n);
	lca.init(201);
	person = 0;
	for (int i = 0; i < n; i++) {
		string father, son;
		cin >> father >> son;
		if (idx.find(father) == idx.end()) {
			idx[father] = ++person;
			name[person] = father;
		}
		if (idx.find(son) == idx.end()) {
			idx[son] = ++person;
			name[person] = son;
		}
		lca.addEdge(idx[father], idx[son], 1);
		deg[idx[son]]++;
	}
	for (int i = 1; i <= person; i++)
		if (deg[i] == 0) lca.addEdge(0, i, 1);
	lca.solve(0);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		string a, b;
		cin >> a >> b;
		if (idx.find(a) == idx.end() || idx.find(b) == idx.end()) {
			cout << -1 << endl;
			continue;
		}
		int common = lca.query(idx[a], idx[b]);
		if (common == 0) cout << -1 << endl;
		else {
			cout << name[common] << endl;
		}
	}
	return 0;
}

