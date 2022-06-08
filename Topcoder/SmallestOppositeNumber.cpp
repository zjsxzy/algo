#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class SmallestOppositeNumber {
	public:
	int construct(int X) {
        int x = X;
        vector<int> vst(10);
        if (x == 0) vst[0] = 1;
        while (x) {
            vst[x % 10] = 1;
            x /= 10;
        }
        string s;
        for (int i = 0; i < 10; i++) {
            if (!vst[i]) s += (char)(i + '0');
        }
        sort(s.begin(), s.end());
        if (s[0] == '0' && (int)s.size() > 1) {
            swap(s[0], s[1]);
        }
        return stoi(s);
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2024868; int Arg1 = 13579; verify_case(0, Arg1, construct(Arg0)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 123456789; verify_case(1, Arg1, construct(Arg0)); }
	void test_case_2() { int Arg0 = 123456798; int Arg1 = 0; verify_case(2, Arg1, construct(Arg0)); }
	void test_case_3() { int Arg0 = 45678; int Arg1 = 10239; verify_case(3, Arg1, construct(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	SmallestOppositeNumber ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
