#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


class PerfectParty {
    public:
    long long invite(vector <int> candies) {
        int n = candies.size(), m = 0;
        for (auto c: candies) m += c;
        vector<vector<LL>> dp(n + 1, vector<LL>(m + 1));
        auto newdp = dp;
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            int c = candies[i - 1];
            newdp = dp;
            for (int j = 0; j < i; j++) {
                for (int k = 0; k + c <= m; k++) {
                    newdp[j + 1][k + c] += dp[j][k];
                }
            }
            dp = newdp;
        }
        LL res = 0;
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= m; k++) {
                if (k % (j + 1) == 0) {
                    res += dp[j][k];
                }
            }
        }
        return res;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 16LL; verify_case(0, Arg1, invite(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(1, Arg1, invite(Arg0)); }
	void test_case_2() { int Arr0[] = {0, 0, 0, 0, 125}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 20LL; verify_case(2, Arg1, invite(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 31LL; verify_case(3, Arg1, invite(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  PerfectParty ___test;
  ___test.run_test(-1);
  return 0;
}
// END CUT HERE
