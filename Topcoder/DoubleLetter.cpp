#line 2 "DoubleLetter.cpp"
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


class DoubleLetter {
    public:
    string ableToSolve(string S) {
		int i = 1;
		while (i < S.size()) {
			if (i > 0 && S[i] == S[i - 1]) {
				S = S.substr(0, i - 1) + S.substr(i + 1);
				i--;
			} else {
				i++;
			}
		}
		return S == "" ? "Possible" : "Impossible";
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aabccb"; string Arg1 = "Possible"; verify_case(0, Arg1, ableToSolve(Arg0)); }
	void test_case_1() { string Arg0 = "aabccbb"; string Arg1 = "Impossible"; verify_case(1, Arg1, ableToSolve(Arg0)); }
	void test_case_2() { string Arg0 = "abcddcba"; string Arg1 = "Possible"; verify_case(2, Arg1, ableToSolve(Arg0)); }
	void test_case_3() { string Arg0 = "abab"; string Arg1 = "Impossible"; verify_case(3, Arg1, ableToSolve(Arg0)); }
	void test_case_4() { string Arg0 = "aaaaaaaaaa"; string Arg1 = "Possible"; verify_case(4, Arg1, ableToSolve(Arg0)); }
	void test_case_5() { string Arg0 = "aababbabbaba"; string Arg1 = "Impossible"; verify_case(5, Arg1, ableToSolve(Arg0)); }
	void test_case_6() { string Arg0 = "zzxzxxzxxzzx"; string Arg1 = "Possible"; verify_case(6, Arg1, ableToSolve(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    DoubleLetter ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
