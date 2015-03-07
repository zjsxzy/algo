#line 2 "CartInSupermarketEasy.cpp"
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

const int MAXN = 105;
int dp[MAXN][MAXN];
class CartInSupermarketEasy {
    public:
    int calc(int N, int K) {
		for (int i = 0; i <= N; i++)
			for (int j = 0; j <= K; j++)
				dp[i][j] = -1;
		return solve(N, K);
    }
	int solve(int n, int k) {
		if (dp[n][k] != -1) return dp[n][k];
		if (n == 0) return dp[n][k] = 0;
		int ret = solve(n - 1, k) + 1;
		if (k > 0) {
			for (int x = 1; x < n; x++) {
				for (int y = 0; y < k; y++) {
					ret = min(ret, max(solve(x, y), solve(n - x, k - 1 - y)) + 1);
				}
			}
		}
		return dp[n][k] = ret;
	}
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 0; int Arg2 = 5; verify_case(0, Arg2, calc(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 4; verify_case(1, Arg2, calc(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 4; int Arg2 = 6; verify_case(2, Arg2, calc(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 100; int Arg2 = 4; verify_case(3, Arg2, calc(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 45; int Arg1 = 5; int Arg2 = 11; verify_case(4, Arg2, calc(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 8; verify_case(5, Arg2, calc(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    CartInSupermarketEasy ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
