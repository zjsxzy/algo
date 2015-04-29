#line 2 "RandomPancakeStackDiv2.cpp"
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

const int MAXN = 255;
double dp[MAXN][MAXN];
class RandomPancakeStackDiv2 {
    public:
    double expectedDeliciousness(vector <int> d) {
		int n = d.size();
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			dp[1][i] = 1.0 / n;
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = j + 1; k <= n; k++) {
					dp[i][j] += dp[i - 1][k] / (n - i + 1);
				}
			}
		}
		double res = 0.0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				res += dp[i][j] * d[j - 1];
			}
		}
		return res;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.6666666666666667; verify_case(0, Arg1, expectedDeliciousness(Arg0)); }
	void test_case_1() { int Arr0[] = {10,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 20.0; verify_case(1, Arg1, expectedDeliciousness(Arg0)); }
	void test_case_2() { int Arr0[] = {3,6,10,9,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 9.891666666666667; verify_case(2, Arg1, expectedDeliciousness(Arg0)); }
	void test_case_3() { int Arr0[] = {10,9,8,7,6,5,4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 10.999999724426809; verify_case(3, Arg1, expectedDeliciousness(Arg0)); }
	void test_case_4() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 7.901100088183421; verify_case(4, Arg1, expectedDeliciousness(Arg0)); }
	void test_case_5() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.7182818011463845; verify_case(5, Arg1, expectedDeliciousness(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    RandomPancakeStackDiv2 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
