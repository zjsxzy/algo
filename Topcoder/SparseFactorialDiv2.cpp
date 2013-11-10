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

class SparseFactorialDiv2 {
public:
	long long countMod(long long t, long long m, long long r) {
		// count the number of x s.t x == r (mod m) && x <= t
		if (t % m >= r) return t / m + 1;
		else return t / m;
	}
	long long calc(long long t, long long divisor) {
		if (t == 0) return 0;
		vector<int> bestK(divisor, -1);
		for (long long k = 0; k * k < t; k++) {
			if (bestK[k * k % divisor] == -1) {
				bestK[k * k % divisor] = k;
			}
		}
		long long res = 0;
		for (int r = 0; r < divisor; r++) {
			if (bestK[r] == -1) continue;
			long long k = bestK[r];
			long long upper = t, lower = k * k + 1;
			res += countMod(upper, divisor, r) - countMod(lower, divisor, r);
		}
		return res;
	}
    long long getCount (long long lo, long long hi, long long divisor) {
		long long rr = calc(hi, divisor);
		long long ll = calc(lo - 1, divisor);
		//cout << ll << " " << rr << endl;
		return rr - ll;
    }


    
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 4LL; long long Arg1 = 8LL; long long Arg2 = 3LL; long long Arg3 = 3LL; verify_case(0, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_1() { long long Arg0 = 9LL; long long Arg1 = 11LL; long long Arg2 = 7LL; long long Arg3 = 1LL; verify_case(1, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_2() { long long Arg0 = 1LL; long long Arg1 = 1000000000000LL; long long Arg2 = 2LL; long long Arg3 = 999999999999LL; verify_case(2, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_3() { long long Arg0 = 16LL; long long Arg1 = 26LL; long long Arg2 = 11LL; long long Arg3 = 4LL; verify_case(3, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_4() { long long Arg0 = 10000LL; long long Arg1 = 20000LL; long long Arg2 = 997LL; long long Arg3 = 1211LL; verify_case(4, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_5() { long long Arg0 = 123456789LL; long long Arg1 = 987654321LL; long long Arg2 = 71LL; long long Arg3 = 438184668LL; verify_case(5, Arg3, getCount(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    SparseFactorialDiv2 ___test;
    for (int i = 0; i < 6; i++)
        ___test.run_test(i);
    return 0;
}
// END CUT HERE
