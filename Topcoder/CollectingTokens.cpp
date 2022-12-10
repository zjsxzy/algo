#line 2 "CollectingTokens.cpp"
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
int n;
vector<int> adj[MAXN], T, G[MAXN];
int dp[MAXN][MAXN][101][2];
class CollectingTokens {
    public:
    int maxTokens(vector <int> A, vector <int> B, vector <int> tokens, int L) {
        n = tokens.size();
        T = tokens;
        for (int i = 0; i < n; i++) {
            adj[i].clear(); G[i].clear();
        }
        for (int i = 0; i < n - 1; i++) {
            add_edge(A[i] - 1, B[i] - 1);
        }
        memset(dp, -1, sizeof(dp));
        dfs(0, -1);
        return f(0, 0, L, 0) + tokens[0];
    }

    int f(int pos, int e_idx, int L, bool back) {
        if (dp[pos][e_idx][L][back] != -1) return dp[pos][e_idx][L][back];
        int res = 0;
        if (e_idx == G[pos].size() || L <= 0) res = 0;
        else {
            int to = G[pos][e_idx];
            for (int i = 0; i <= L; i++) {
                if (L - i >= 2) {
                    int temp = T[to] + f(to, 0, i, 1) + f(pos, e_idx + 1, L - i - 2, back);
                    res = max(res, temp);
                }
                if (L - i >= 1 && back == 0) { // not return
                    int temp = T[to] + f(to, 0, i, 0) + f(pos, e_idx + 1, L - i - 1, 1);
                    res = max(res, temp);
                }
            }
            int temp = f(pos, e_idx + 1, L, back);
            res = max(res, temp);
        }
        return dp[pos][e_idx][L][back] = res;
    }

    void dfs(int curr, int pre) {
        for (vector<int>::iterator it = adj[curr].begin(); it != adj[curr].end(); it++) {
            if (*it != pre) {
                G[curr].PB(*it);
                dfs(*it, curr);
            }
        }
    }

    void add_edge(int u, int v) {
        // cout << u << " " << v << endl;
        adj[u].PB(v);
        adj[v].PB(u);
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; int Arg4 = 8; verify_case(0, Arg4, maxTokens(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; int Arg4 = 14; verify_case(1, Arg4, maxTokens(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {1,2,5,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,4,1,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6,1,6,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 16; verify_case(2, Arg4, maxTokens(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {9,1,7,10,5,8,3,4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6,6,9,6,6,1,1,6,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,2,1,6,3,7,8,5,2,9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; int Arg4 = 26; verify_case(3, Arg4, maxTokens(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {25,22,35,42,40,9,32,12,37,44,23,1,24,28,20,4,26,33,11,48,34,6,16,50,46,17,8,43,18,30,31,36,39,13,
10,45,3,47,15,2,29,19,7,14,41,49,38,27,21}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,5,25,25,25,42,25,40,5,35,25,32,42,9,32,23,40,25,20,33,26,37,12,1,48,24,22,25,11,24,48,34,18,9,50,42,16,40,1,
10,47,22,48,44,48,1,4,46,47}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6,9,4,9,5,8,6,4,4,1,4,8,3,4,5,8,5,6,4,9,7,9,7,9,5,2,7,2,7,7,5,9,5,8,5,7,1,9,3,9,3,6,4,5,5,4,7,9,2,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 48; int Arg4 = 194; verify_case(4, Arg4, maxTokens(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    CollectingTokens ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
