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

typedef int F;
#define inf (1 << 29)
#define maxV 105
#define maxE 10005
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

	bool mkS[maxV], mkT[maxV];
	void traS(int u) {
		mkS[u] = true;
		for (int i = last[u], v; i != -1; i = prev[i]) {
			if (cap[i] - flow[i] > 0 && !mkS[v = to[i]]) {
				traS(v);
			}
		}
	}

	void traT(int u) {
		mkT[u] = true;
		for (int i = last[u], v; i != -1; i = prev[i]) {
			if (cap[i ^ 1] - flow[i ^ 1] && !mkT[v = to[i]]) {
				traT(v);
			}
		}
	}

	void work(int s, int t) {
		memset(mkS, 0, sizeof(mkS));
		memset(mkT, 0, sizeof(mkT));
		traS(s);
		traT(t);
	}
}mf;

int main(int argc, char const *argv[])
{
	mf.init(9);
	mf.addCap(0, 1, 5);
	mf.addCap(0, 3, 14);
	mf.addCap(1, 2, 4);
	mf.addCap(1, 4, 5);
	mf.addCap(1, 5, 4);
	mf.addCap(2, 5, 3);
	mf.addCap(3, 1, 13);
	mf.addCap(3, 6, 5);
	mf.addCap(3, 7, 2);
	mf.addCap(4, 3, 6);
	mf.addCap(4, 7, 6);
	mf.addCap(5, 4, 4);
	mf.addCap(5, 8, 6);
	mf.addCap(5, 7, 3);
	mf.addCap(6, 7, 3);
	mf.addCap(7, 8, 12);
	cout << mf.solve(0, 8) << endl;
	mf.work(0, 8);
	for (int i = 0; i < 9; i++)
		if (mf.mkS[i]) cout << i << " ";
	cout << endl;
	for (int i = 0; i < 9; i++)
		if (mf.mkT[i]) cout << i << " ";
	cout << endl;
	return 0;
}