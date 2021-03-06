#include <map>
#include <set>
#include <list>
#include <list>
#include <cmath>
#include <queue>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 5005;
const int Letter = 26;
double dp[MAXN][MAXN];
class PalindromicSubstringsDiv1 {
public:
    double expectedPalindromes (vector <string> S1, vector <string> S2) {
		string str1 = "", str2 = "";
		for (int i = 0; i < S1.size(); i++)
			str1 += S1[i];
		for (int i = 0; i < S2.size(); i++)
			str2 += S2[i];
		string str = str1 + str2;
		int n = str.size();
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++) {
			dp[i][i] = 1.0;
			if (i + 1 < n) {
				if (str[i] == '?' || str[i + 1] == '?') dp[i][i + 1] = 1.0 / Letter;
				else if (str[i] == str[i + 1]) dp[i][i + 1] = 1.0;
			}
		}
		for (int l = 3; l <= n; l++) {
			for (int i = 0; i + l - 1 < n; i++) {
				int j = i + l - 1;
				if (str[i] == '?' || str[j] == '?') dp[i][j] = dp[i + 1][j - 1] * 1.0 / Letter;
				else if (str[i] == str[j]) dp[i][j] = dp[i + 1][j - 1];
			}
		}
		double ret = 0;
		for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++)
				ret += dp[i][j];
		return ret;
    }


    
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"a","a",""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.0; verify_case(0, Arg2, expectedPalindromes(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"z??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 3.115384615384615; verify_case(1, Arg2, expectedPalindromes(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"ab","c"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"??","a?"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 7.315088757396449; verify_case(2, Arg2, expectedPalindromes(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"?"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(3, Arg2, expectedPalindromes(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"ab?def","?"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"f??a"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 12.545971779699588; verify_case(4, Arg2, expectedPalindromes(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PalindromicSubstringsDiv1 ___test;
    for (int i = 0; i < 6; i++)
        ___test.run_test(i);
    return 0;
}
// END CUT HERE
