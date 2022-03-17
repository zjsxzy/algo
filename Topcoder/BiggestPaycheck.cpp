#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class BiggestPaycheck {
	public:
	int findBiggest(int a, int b, int c) {
        return max(max(a, b), c);
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 50; int Arg1 = 55; int Arg2 = 60; int Arg3 = 60; verify_case(0, Arg3, findBiggest(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 999; int Arg1 = 1; int Arg2 = 2; int Arg3 = 999; verify_case(1, Arg3, findBiggest(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 50; int Arg1 = 50; int Arg2 = 10; int Arg3 = 50; verify_case(2, Arg3, findBiggest(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	BiggestPaycheck ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
