#line 2 "TheNicePair.cpp"
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


class TheNicePair {
    public:
    int solve(vector <int> A) {
		int n = A.size();
		if (n == 1 && A[0] != 1) {
			return 0;
		}
		int ret = -1;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				bool flag = false;
				for (int d = 2; d <= 1000 && !flag; d++) {
					int cnt = 0;
					for (int k = i; k <= j; k++) {
						if (A[k] % d == 0) {
							cnt++;
							if (cnt > (j - i) / 2) {
								flag = true;
								break;
							}
						}
					}
				}
				if (flag) {
					ret = max(ret, j - i);
				}
			}
		}
		return ret;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5,5,5,5,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { int Arr0[] = {2,3,5,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { int Arr0[] = {8,8,5,5,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, solve(Arg0)); }
	void test_case_4() { int Arr0[] = {1,1000,1000,1,1000,1,999}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, solve(Arg0)); }
	void test_case_5() { int Arr0[] = {1000,1,1,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(5, Arg1, solve(Arg0)); }
	void test_case_6() { int Arr0[] = {1,1,953,1,1,1,1,1,1,1,1,1,1,1,1,953,1,953,953,1,1,1,1,1,1,1,953,953,953,1,1,1,1,1,953,953,1,1,1,953,953,953,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(6, Arg1, solve(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    TheNicePair ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
