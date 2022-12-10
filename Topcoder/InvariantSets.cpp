#line 2 "InvariantSets.cpp"
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

const int MAXN = 55;
struct Graph {
	int n, size, depth;
	vector<int> adj[MAXN];
	int low[MAXN], dfn[MAXN], id[MAXN];
	bool vis[MAXN];
	stack<int> S;

	void init(int n) {
		this->n = n;
		for (int i = 0; i <= n; i++)
			adj[i].clear();
		memset(id, 0, sizeof(id));
		memset(vis, 0, sizeof(vis));
		while (!S.empty()) S.pop();
	}

	void addEdge(int u, int v) {
		adj[u].PB(v);
	}

	void Tarjan(int u) {
		dfn[u] = low[u] = depth++;
		S.push(u);
		vis[u] = true;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			if (dfn[v] == -1) {
				Tarjan(v);
				low[u] = min(low[u], low[v]);
			} else if (vis[v]) {
				low[u] = min(low[u], dfn[v]);
			}
		}
		if (low[u] == dfn[u]) {
			size++;
			int v;
			do {
				v = S.top();
				S.pop();
				id[v] = size;
				vis[v] = false;
			} while (u != v);
		}
	}

	void SCC() {
		memset(dfn, -1, sizeof(dfn));
		size = 0;
		depth = 1;
		for (int i = 0; i < n; i++)
			if (dfn[i] == -1) Tarjan(i);
	}

}g;

class InvariantSets {
    public:
    long long countSets(vector <int> f) {
		int n = f.size();
		g.init(n);
		for (int i = 0; i < n; i++) {
			g.addEdge(i, f[i]);
		}
		g.SCC();
		
		adj.clear();
		adj.resize(g.size + 1);
		memset(deg, 0, sizeof(deg));
		for (int i = 0; i < n; i++) {
			int u = g.id[i], v = g.id[f[i]];
			if (u != v) {
				adj[v].PB(u);
				deg[u]++;
				// cout << u << "->" << v << endl;
			}
		}
		memset(dp, -1, sizeof(dp));
		LL ret = 1;
		for (int i = 1; i <= g.size; i++) {
			if (deg[i] == 0) {
				dfs(i);
				ret *= dp[i];
			}
		}
		return ret;
    }
	
	void dfs(int u) {
		dp[u] = 1;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			dfs(v);
			dp[u] *= dp[v];
		}
		dp[u]++;
	}
	
	vector<vector<int> > adj;
	int deg[MAXN];
	LL dp[MAXN];
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 5LL; verify_case(0, Arg1, countSets(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(1, Arg1, countSets(Arg0)); }
	void test_case_2() { int Arr0[] = {0,0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 5LL; verify_case(2, Arg1, countSets(Arg0)); }
	void test_case_3() { int Arr0[] = {0,1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 64LL; verify_case(3, Arg1, countSets(Arg0)); }
	void test_case_4() { int Arr0[] = {12, 10, 0, 4, 0, 6, 3, 8, 9, 14, 1, 5, 6, 12, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 90LL; verify_case(4, Arg1, countSets(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    InvariantSets ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
