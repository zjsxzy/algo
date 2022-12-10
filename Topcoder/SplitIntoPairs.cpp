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

class SplitIntoPairs {
public:
    int makepairs (vector <int> A, int X) {
		vector<int> neg, pos;
		int zero = 0;
		for (int i = 0; i < A.size(); i++) {
			if (A[i] > 0) pos.PB(A[i]);
			else if (A[i] < 0) neg.PB(A[i]);
			else zero++;
		}
		sort(neg.begin(), neg.end());
		sort(pos.begin(), pos.end());
		if (neg.size() % 2 == 0) return A.size() / 2;
		if (zero) return A.size() / 2;
		if ((LL)neg[neg.size() - 1] * pos[0] >= X) return A.size() / 2;
		else return A.size() / 2 - 1;
    }


    
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; int Arg2 = 0; verify_case(0, Arg2, makepairs(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; int Arg2 = 1; verify_case(1, Arg2, makepairs(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-5,-4,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; int Arg2 = 2; verify_case(2, Arg2, makepairs(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {5,-7,8,-2,-5,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -7; int Arg2 = 3; verify_case(3, Arg2, makepairs(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {3,4,5,6,6,-6,-4,-10,-1,-9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -2; int Arg2 = 4; verify_case(4, Arg2, makepairs(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1000000,1000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -5; int Arg2 = 1; verify_case(5, Arg2, makepairs(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    SplitIntoPairs ___test;
    for (int i = 0; i < 6; i++)
        ___test.run_test(i);
    return 0;
}
// END CUT HERE
