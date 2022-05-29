#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class MaxDiffBetweenCards {
	public:
	long long solve(int N) {
        if (N == 1) return 0;
        string a = "";
        for (int i = 0; i < N / 2; i++) a += '9';
        a += '1';
        if (N & 1) for (int i = 0; i < N / 2; i++) a += '0';
        else for (int i = 0; i < N / 2 - 1; i++) a += '0';
        string b = "1";
        if (N & 1) for (int i = 0; i < N / 2; i++) b += '0';
        else for (int i = 0; i < N / 2 - 1; i++) b += '0';
        for (int i = 0; i < N / 2; i++) b += '9';
        return stoll(a) - stoll(b);
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; long long Arg1 = 0LL; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { int Arg0 = 2; long long Arg1 = 72LL; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { int Arg0 = 4; long long Arg1 = 8811LL; verify_case(2, Arg1, solve(Arg0)); }

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
