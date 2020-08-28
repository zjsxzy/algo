#line 2 "Similars.cpp"
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

int num[1200];
class Similars {
    public:
    int maxsim(int L, int R) {
		memset(num, 0, sizeof(num));
		for (int a = L; a <= R; a++) {
			int st = 0;
			int x = a;
			while (x) {
				st |= 1 << (x % 10);
				x /= 10;
			}
			num[st]++;
		}
		// cout << num[2] << endl;
		int ret = 0;
		for (int i = 0; i < (1 << 10); i++) {
			int cnt = 0;
			for (int j = 0; j < (1 << 10); j++) {
				// cout << i << endl;
				if ((i & j) == i)
					cnt += num[j];
			}
			if (cnt >= 2) {
				int bit = 0, x = i;
				while (x) {
					if (x & 1) bit++;
					x >>= 1;
				}
				ret = max(ret, bit);
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
	void test_case_0() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 1; verify_case(0, Arg2, maxsim(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 99; int Arg2 = 2; verify_case(1, Arg2, maxsim(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 99; int Arg1 = 100; int Arg2 = 0; verify_case(2, Arg2, maxsim(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1000; int Arg1 = 1010; int Arg2 = 2; verify_case(3, Arg2, maxsim(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 444; int Arg1 = 454; int Arg2 = 2; verify_case(4, Arg2, maxsim(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    Similars ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
