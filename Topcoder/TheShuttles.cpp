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

class TheShuttles {
public:
    int getLeastCost (vector <int> cnt, int baseCost, int seatCost) {
		int ret = 0x3f3f3f3f;
		int mx = 0, n = cnt.size();
		for (int i = 0; i < n; i++)
			mx = max(mx, cnt[i]);
		for (int seat = 1; seat <= mx; seat++) {
			int tot = 0;
			for (int i = 0; i < n; i++) {
				int k = 1;
				while (k * seat < cnt[i]) {
					k++;
				}
				tot += k;
			}
			ret = min(ret, tot * (baseCost + seat * seatCost));
		}
		return ret;
    }


    
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; int Arg2 = 5; int Arg3 = 75; verify_case(0, Arg3, getLeastCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {9, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; int Arg2 = 5; int Arg3 = 150; verify_case(1, Arg3, getLeastCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {9, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 5; int Arg3 = 105; verify_case(2, Arg3, getLeastCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {51, 1, 77, 14, 17, 10, 80}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32; int Arg2 = 40; int Arg3 = 12096; verify_case(3, Arg3, getLeastCost(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    TheShuttles ___test;
    for (int i = 0; i < 6; i++)
        ___test.run_test(i);
    return 0;
}
// END CUT HERE
