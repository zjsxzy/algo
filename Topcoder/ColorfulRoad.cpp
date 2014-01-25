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

class ColorfulRoad {
public:
    int getMin (string road) {
		int n = road.size();
		vector<int> dp(n);
		for (int i = 1; i < n; i++) dp[i] = -1;
		for (int i = 0; i < n; i++) {
			if (dp[i] == -1) continue;
			for (int j = 1; i + j < n; j++) {
				if (check(road[i], road[i + j])) {
					if (dp[i + j] == -1 || dp[i] + j * j < dp[i + j]) {
						dp[i + j] = dp[i] + j * j;
					}
				}
			}
		}
		return dp[n - 1];
    }

	bool check(char a, char b) {
		if (a == 'R' && b == 'G') return true;
		if (a == 'G' && b == 'B') return true;
		if (a == 'B' && b == 'R') return true;
		return false;
	}


    
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RGGGB"; int Arg1 = 8; verify_case(0, Arg1, getMin(Arg0)); }
	void test_case_1() { string Arg0 = "RGBRGBRGB"; int Arg1 = 8; verify_case(1, Arg1, getMin(Arg0)); }
	void test_case_2() { string Arg0 = "RBBGGGRR"; int Arg1 = -1; verify_case(2, Arg1, getMin(Arg0)); }
	void test_case_3() { string Arg0 = "RBRRBGGGBBBBR"; int Arg1 = 50; verify_case(3, Arg1, getMin(Arg0)); }
	void test_case_4() { string Arg0 = "RG"; int Arg1 = 1; verify_case(4, Arg1, getMin(Arg0)); }
	void test_case_5() { string Arg0 = "RBRGBGBGGBGRGGG"; int Arg1 = 52; verify_case(5, Arg1, getMin(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    ColorfulRoad ___test;
    for (int i = 0; i < 6; i++)
        ___test.run_test(i);
    return 0;
}
// END CUT HERE
