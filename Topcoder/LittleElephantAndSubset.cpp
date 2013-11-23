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

const LL MOD = 1000000007;
class LittleElephantAndSubset {
public:
	int n;
	LL count[1 << 10], dp[1 << 10];
	void generate(LL x, int mask) {
		if (x > n) return;
		count[mask]++;
		for (int i = 0; i <= 9; i++)
			if (!(mask & (1 << i))) {
				generate(x * 10 + i, mask | (1 << i));
			}
	}
    int getNumber (int N) {
		n = N;
		memset(count, 0, sizeof(count));
		for (int i = 1; i <= 9; i++)
			generate(i, 1 << i);
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 0; i < (1 << 10); i++) {
			for (int j = i + 1; j < (1 << 10); j++) {
				if (i & j) continue;
				dp[i | j] = (dp[i | j] + dp[i] * count[j]) % MOD;
			}
		}
		int ret = 0;
		for (int i = 1; i < (1 << 10); i++)
			ret = (ret + dp[i]) % MOD;
		return ret;
    }


    
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 7; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 767; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { int Arg0 = 47; int Arg1 = 25775; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { int Arg0 = 4777447; int Arg1 = 66437071; verify_case(3, Arg1, getNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    LittleElephantAndSubset ___test;
    for (int i = 0; i < 6; i++)
        ___test.run_test(i);
    return 0;
}
// END CUT HERE
