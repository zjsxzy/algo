#line 2 "FibonacciDiv2.cpp"
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


class FibonacciDiv2 {
    public:
    int find(int N) {
		vector<int> fib;
		fib.PB(1); fib.PB(1);
		for (int i = 2; fib[i - 1] + fib[i - 2] <= 10000000; i++) {
			fib.PB(fib[i - 1] + fib[i - 2]);
		}
		int ret = 0x3f3f3f3f;
		for (int i = 0; i < fib.size(); i++) {
			ret = min(ret, abs(fib[i] - N));
		}
		return ret;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 0; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { int Arg0 = 13; int Arg1 = 0; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 2; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { int Arg0 = 19; int Arg1 = 2; verify_case(3, Arg1, find(Arg0)); }
	void test_case_4() { int Arg0 = 1000000; int Arg1 = 167960; verify_case(4, Arg1, find(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    FibonacciDiv2 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
