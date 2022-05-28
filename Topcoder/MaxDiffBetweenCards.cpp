#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class MaxDiffBetweenCards {
	public:
	long long solve(int N) {
        if (N == 1) return 0;
        if (N == 2) return 72;
        LL ten = 1;
        for (int i = 0; i < N; i++) {
            ten *= 10;
        }
        LL a = ten - 90;
        LL b = ten / 10;
        b += ten / 100 - 1;
        return a - b;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; long long Arg1 = 0LL; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { int Arg0 = 2; long long Arg1 = 72LL; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { int Arg0 = 3; long long Arg1 = 8811LL; verify_case(2, Arg1, solve(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	MaxDiffBetweenCards ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
