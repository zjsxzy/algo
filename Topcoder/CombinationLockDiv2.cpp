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

const int inf = 0x3f3f3f3f;
int dp[55][55][10];
int diff(char a, char b) {
	return min(abs(a - b), 10 - abs(a - b));
}
char add(char c, int i) {
	return (char)('0' + (c - '0' + i) % 10);
}
class CombinationLockDiv2 {
public:
    int minimumMoves (string S, string T) {
		int n = S.size();
		for (int i = 0; i < n; i++)
			for (int k = 0; k <= 9; k++)
				dp[i][i][k] = diff(S[i], add(T[i], k));
		for (int l = 2; l <= n; l++) {
			for (int i = 0; i + l - 1 < n; i++) {
				int j = i + l - 1;
				for (int a = 0; a <= 9; a++) {
					int ret = inf;
					for (int mid = i; mid < j; mid++) {
						for (int b = 0; b <= 9; b++) {
							ret = min(ret, dp[i][mid][b] + dp[mid+1][j][b] + min(abs(a - b), 10 - abs(a - b)));
						}
					}
					dp[i][j][a] = ret;
				}
			}
		}
		return dp[0][n - 1][0];
    }


    
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "123"; string Arg1 = "112"; int Arg2 = 1; verify_case(0, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "1"; string Arg1 = "7"; int Arg2 = 4; verify_case(1, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "607"; string Arg1 = "607"; int Arg2 = 0; verify_case(2, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "1234"; string Arg1 = "4567"; int Arg2 = 3; verify_case(3, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "020"; string Arg1 = "909"; int Arg2 = 2; verify_case(4, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "4423232218340"; string Arg1 = "6290421476245"; int Arg2 = 18; verify_case(5, Arg2, minimumMoves(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    CombinationLockDiv2 ___test;
    for (int i = 0; i < 6; i++)
        ___test.run_test(i);
    return 0;
}
// END CUT HERE
