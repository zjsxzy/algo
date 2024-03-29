#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class NonbinarySearch {
	public:
	int search(int N) {
        if (N <= 2) return N;
        return 1 + search((N + 2) / 2);
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; verify_case(0, Arg1, search(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; verify_case(1, Arg1, search(Arg0)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 6; verify_case(2, Arg1, search(Arg0)); }
	void test_case_3() { int Arg0 = 1000000; int Arg1 = 22; verify_case(3, Arg1, search(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	NonbinarySearch ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
