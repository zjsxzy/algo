#line 2 "WalkOverATree.cpp"
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
vector<int> adj[MAXN];
int dis[MAXN];
class WalkOverATree {
    public:
    int maxNodesVisited(vector <int> parent, int L) {
        int n = parent.size() + 1;
        for (int i = 0; i < n; i++) {
            adj[i].clear();
        }
        for (int i = 0; i < n; i++) dis[i] = -1;
        for (int i = 0; i < n - 1; i++) {
            adj[i + 1].PB(parent[i]);
            adj[parent[i]].PB(i + 1);
        }
        queue<int> q;
        q.push(0);
        int d = 0;
        dis[0] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            d = max(d, dis[u]);
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i];
                if (dis[v] == -1) {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
        if (L <= d) return L + 1;
        else return min(n, d + 1 + (L - d) / 2);
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, maxNodesVisited(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; verify_case(1, Arg2, maxNodesVisited(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(2, Arg2, maxNodesVisited(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0,0,0,0,2,4,2,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(3, Arg2, maxNodesVisited(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0,0,1,2,3,2,3,1,3,0,1,8,6,8,0,5,15,0,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 5; verify_case(4, Arg2, maxNodesVisited(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {0,0,0,1,1,3,5,1,4,5,2,2,10,5,10,10,11,13,8,3,18,15,20,20,23,8,11,26,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 26; int Arg2 = 17; verify_case(5, Arg2, maxNodesVisited(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {0, 0, 2, 0}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 5; verify_case(6, Arg2, maxNodesVisited(Arg0, Arg1)); }
	void test_case_7() { int Arr0[] = {0, 0, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 4; verify_case(7, Arg2, maxNodesVisited(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    WalkOverATree ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
