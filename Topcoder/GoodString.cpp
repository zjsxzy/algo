#line 2 "GoodString.cpp"
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


class GoodString {
    public:
    string isGood(string s) {
        int n = s.size(), curr = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                curr++;
            } else {
                curr--;
                if (curr < 0) return "Bad";
            }
        }
        if (curr == 0) return "Good";
        else return "Bad";
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ab"; string Arg1 = "Good"; verify_case(0, Arg1, isGood(Arg0)); }
	void test_case_1() { string Arg0 = "aab"; string Arg1 = "Bad"; verify_case(1, Arg1, isGood(Arg0)); }
	void test_case_2() { string Arg0 = "aabb"; string Arg1 = "Good"; verify_case(2, Arg1, isGood(Arg0)); }
	void test_case_3() { string Arg0 = "ababab"; string Arg1 = "Good"; verify_case(3, Arg1, isGood(Arg0)); }
	void test_case_4() { string Arg0 = "abaababababbaabbaaaabaababaabbabaaabbbbbbbb"; string Arg1 = "Bad"; verify_case(4, Arg1, isGood(Arg0)); }
	void test_case_5() { string Arg0 = "aaaaaaaabbbaaabaaabbabababababaabbbbaabbabbbbbbabb"; string Arg1 = "Good"; verify_case(5, Arg1, isGood(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    GoodString ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
