#line 2 "SimilarDNA.cpp"
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class SimilarDNA {
	public:
	string areSimilar(string A, string B) {
        int n = A.size(), m = B.size();
        vector<vector<int> > dp(n + 1, vector<int>(m + 1));
		for (int i = 1; i <= n; i++)
			dp[i][0] = i;
		for (int j = 1; j <= m; j++)
			dp[0][j] = j;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = dp[i - 1][j - 1] + (A[i - 1] == B[j - 1] ? 0 : 1);
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
			}
		}
        if (dp[n][m] <= 2) return "similar";
        else return "distinct";
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AAAAA"; string Arg1 = "AACAACA"; string Arg2 = "similar"; verify_case(0, Arg2, areSimilar(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "AACAACA"; string Arg1 = "AAAAA"; string Arg2 = "similar"; verify_case(1, Arg2, areSimilar(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "AACAACA"; string Arg1 = "AAGAATA"; string Arg2 = "similar"; verify_case(2, Arg2, areSimilar(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "CGATCGAT"; string Arg1 = "CATCGAG"; string Arg2 = "similar"; verify_case(3, Arg2, areSimilar(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "CGATCGAT"; string Arg1 = "CGATCGAT"; string Arg2 = "similar"; verify_case(4, Arg2, areSimilar(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "CGATATATAGGA"; string Arg1 = "GGATATACCATA"; string Arg2 = "distinct"; verify_case(5, Arg2, areSimilar(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "AAAAA"; string Arg1 = "AA"; string Arg2 = "distinct"; verify_case(6, Arg2, areSimilar(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	SimilarDNA ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
