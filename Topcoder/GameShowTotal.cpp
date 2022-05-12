#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class GameShowTotal {
	public:
	string verify(int N, vector <int> A, int W) {
        if (W == 0) return "possible";
        int curr = 0;
        for (int i = N - 1; i >= 0; i--) {
            curr += A[i];
            if (W == curr) return "possible";
        }
        return "impossible";
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {10, 20, 30, 40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; string Arg3 = "possible"; verify_case(0, Arg3, verify(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {10, 20, 30, 40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; string Arg3 = "possible"; verify_case(1, Arg3, verify(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 5; int Arr1[] = {10, 20, 30, 1000, 40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; string Arg3 = "impossible"; verify_case(2, Arg3, verify(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 6; int Arr1[] = {10, 20, 30, 40, 1000, 50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1050; string Arg3 = "possible"; verify_case(3, Arg3, verify(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	GameShowTotal ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
