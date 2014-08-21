#line 2 "FixedDiceGameDiv1.cpp"
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

class FixedDiceGameDiv1 {
    public:
    double getExpectation(int a, int b, int c, int d) {
		vector<double> Alice = getProbability(a, b);
		vector<double> Bob = getProbability(c, d);
		double totProb = 0;
		for (int i = a; i <= a * b; i++) {
			for (int j = c; j <= c * d; j++) {
				if (i > j) {
					totProb += Alice[i] * Bob[j];
				}
			}
		}
		
		if (totProb <= 0.0) return -1.0;
		
		double ret = 0;
		for (int i = a; i <= a * b; i++) {
			for (int j = c; j <= c * d; j++) {
				if (i > j) {
					double p = Alice[i] * Bob[j];
					ret += i * (p / totProb);
				}
			}
		}
		return ret;
    }
    
	vector<double> getProbability(int a, int b) {
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1.0;
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= a * b; j++) {
				for (int k = 1; k <= b; k++) {
					if (j - k < 0) continue;
					dp[i][j] += dp[i - 1][j - k] / b;
				}
			}
		}
		vector<double> ret(a * b + 1);
		for (int i = 1; i <= a * b; i++)
			ret[i] = dp[a][i];
		return ret;
	}
	
	double dp[55][2505];
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 1; int Arg3 = 5; double Arg4 = 2.0; verify_case(0, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 3; double Arg4 = 3.0; verify_case(1, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 1; int Arg3 = 1; double Arg4 = 3.4999999999999996; verify_case(2, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 6; int Arg2 = 50; int Arg3 = 30; double Arg4 = -1.0; verify_case(3, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 11; int Arg2 = 50; int Arg3 = 50; double Arg4 = 369.8865999182022; verify_case(4, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    FixedDiceGameDiv1 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
