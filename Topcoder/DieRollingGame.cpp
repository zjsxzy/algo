#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

double dp[105][105];
class DieRollingGame {
	public:
	double winChance(int n, int total) {
        dp[0][0] = 1.0;
        for (int i = 1; i <= total; i++) {
            for (int j = 0; j <= total; j++) {
                dp[i][j] = 0;
            }
        }
        for (int i = 0; i <= total; i++) {
            for (int j = 0; j <= total; j++) {
                if (dp[i][j] > 0) {
                    for (int k = 1; k <= n; k++) {
                        if (j + k > total) continue;
                        dp[i + 1][j + k] += dp[i][j] * 1.0 / n;
                    }
                }
            }
        }
        double res = 0.0;
        for (int i = 1; i <= total; i++) {
            res += dp[i][total];
        }
        return res;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 1; double Arg2 = 0.16666666666666666; verify_case(0, Arg2, winChance(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 2; double Arg2 = 0.3125; verify_case(1, Arg2, winChance(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; double Arg2 = 0.625; verify_case(2, Arg2, winChance(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 20; int Arg1 = 20; double Arg2 = 0.12634750976878192; verify_case(3, Arg2, winChance(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	DieRollingGame ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
