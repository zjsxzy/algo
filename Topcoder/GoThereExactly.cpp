#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class GoThereExactly {
	public:
	string walk(int r1, int c1, int r2, int c2, int s) {
        int d = abs(r1 - r2) + abs(c1 - c2);
        if (s < d || (s - d) % 2 != 0) return "IMPOSSIBLE";
        string res1, res2;
        if (r2 > r1) {
            for (int i = 0; i < r2 - r1; i++) res2 += 'D';
        } else {
            for (int i = 0; i < r1 - r2; i++) res2 += 'U';
        }
        if (c2 > c1) {
            for (int i = 0; i < c2 - c1; i++) res2 += 'R';
        } else {
            for (int i = 0; i < c1 - c2; i++) res2 += 'L';
        }

        bool u = true;
        for (auto c: res2) {
            if (c != 'U') {
                u = false;
                break;
            }
        }
        if (u) {
            // all U
            for (int i = 0; i < (s - d) / 2; i++) res1 += 'L';
            for (int i = 0; i < (s - d) / 2; i++) res1 += 'R';
            return res1 + res2;
        }

        for (int i = 0; i < (s - d) / 2; i++) {
            res1 += 'U';
        }
        for (int i = 0; i < (s - d) / 2; i++) {
            res1 += 'D';
        }
        return res1 + res2;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 7; int Arg2 = 4; int Arg3 = 7; int Arg4 = 0; string Arg5 = ""; verify_case(0, Arg5, walk(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 7; int Arg2 = 4; int Arg3 = 8; int Arg4 = 42; string Arg5 = "IMPOSSIBLE"; verify_case(1, Arg5, walk(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 7; int Arg2 = 4; int Arg3 = 7; int Arg4 = 12; string Arg5 = "UUURRRDDDLLL"; verify_case(2, Arg5, walk(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 4; int Arg3 = 0; int Arg4 = 14; string Arg5 = "LLDDRRDRRRDLLL"; verify_case(3, Arg5, walk(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 18; int Arg1 = 16; int Arg2 = 16; int Arg3 = 13; int Arg4 = 5; string Arg5 = "UULLL"; verify_case(4, Arg5, walk(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	GoThereExactly ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
