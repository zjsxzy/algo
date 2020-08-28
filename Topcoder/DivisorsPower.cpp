#line 2 "DivisorsPower.cpp"
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


class DivisorsPower {
    public:
    long long findArgument(long long n) {
		LL res = -1;
		for (LL pow = 2; 1ll << pow <= n; pow++) {
			LL x = (LL)exp(log(n) / pow);
			while (power(x, pow) > n) {
				x--;
			}
			while (power(x, pow) < n) {
				x++;
			}
			if (power(x, pow) == n && divisor(x) == pow) {
				if (res == -1 || x < res) res = x;
			}
		}
		return res;
    }
	
	long long power(LL x, LL n) {
		LL res = 1;
		for (; n; n >>= 1) {
			if (n & 1) res = res * x;
			x = x * x;
		}
		return res;
	}
	
	LL divisor(LL x) {
		LL res = 0;
		for (LL d = 1; d * d <= x; d++) {
			if (x % d == 0) {
				res += d * d == x ? 1 : 2;
			}
		}
		return res;
	}
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 4LL; long long Arg1 = 2LL; verify_case(0, Arg1, findArgument(Arg0)); }
	void test_case_1() { long long Arg0 = 10LL; long long Arg1 = -1LL; verify_case(1, Arg1, findArgument(Arg0)); }
	void test_case_2() { long long Arg0 = 64LL; long long Arg1 = 4LL; verify_case(2, Arg1, findArgument(Arg0)); }
	void test_case_3() { long long Arg0 = 10000LL; long long Arg1 = 10LL; verify_case(3, Arg1, findArgument(Arg0)); }
	void test_case_4() { long long Arg0 = 2498388559757689LL; long long Arg1 = 49983883LL; verify_case(4, Arg1, findArgument(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    DivisorsPower ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
