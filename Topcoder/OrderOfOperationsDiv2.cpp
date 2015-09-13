#line 2 "OrderOfOperationsDiv2.cpp"
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

const int MAXM = 1 << 22;
const int inf = 1000000000;
int dp[MAXM];
int mask[55];
int n, m;
class OrderOfOperationsDiv2 {
    public:
        int minTime(vector <string> s) {
            n = s.size();
            m = s[0].size();
            memset(mask, 0, sizeof(mask));
            int sum = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (s[i][j] == '1') {
                        mask[i] |= (1 << j);
                    }
                }
                sum |= mask[i];
            }
            for (int s = 0; s < (1 << m); s++) {
                dp[s] = inf;
            }
            dp[0] = 0;
            for (int s = 0; s < (1 << m); s++) {
                for (int i = 0; i < n; i++) {
                    int new_mask = s | mask[i];
                    int k = count(s, mask[i]);
                    int temp = dp[s] + k * k;
                    dp[new_mask] = min(dp[new_mask], temp);
                }
            }
            return dp[sum];
        }

        int count(int s, int t) {
            int ret = 0;
            for (int i = 0; i < m; i++) {
                if (!(s & (1 << i)) && (t & (1 << i))) {
                    ret++;
                }
            }
            return ret;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
 "111",
 "001",
 "010"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, minTime(Arg0)); }
	void test_case_1() { string Arr0[] = {
 "11101",
 "00111",
 "10101",
 "00000",
 "11000"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(1, Arg1, minTime(Arg0)); }
	void test_case_2() { string Arr0[] = {
  "11111111111111111111"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 400; verify_case(2, Arg1, minTime(Arg0)); }
	void test_case_3() { string Arr0[] = {
  "1000",
  "1100",
  "1110"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, minTime(Arg0)); }
	void test_case_4() { string Arr0[] = {
  "111",
  "111",
  "110",
  "100"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, minTime(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    OrderOfOperationsDiv2 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
