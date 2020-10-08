#line 2 "TapeMeasure.cpp"
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

const int MAXN = 100 + 10;
class TapeMeasure {
public:
    vector <string> draw(int leftMark, int rightMark) {
        // generat the whole tape measure
        vector<string> rows(5, "");
        for(int i = 0; i < 2000; ++i) rows[0] += "#";
        for(int i = 0; i < 1000; ++i) rows[1] += "# ";
        for(int i = 0; i < 1000; ++i) rows[2] += "#         ";
        for(int i = 0; i < 1000; ++i) rows[3] += "#                   ";
        for(int i = 0; i < 1000; ++i) rows[4] += "                    ";
         
        for(int i = 0; i <= 990; i += 10) {
            string s = to_string(i);
            for(int j = 0; j < s.length(); ++j)
                rows[4][i * 2 + j] = s[j];
        }
         
        // extract the tape measure in range [leftMark, rightMark]
        vector<string> ans(5, "");
        for(int i = 0; i < 5; ++i) ans[i] = rows[i].substr(leftMark * 2, (rightMark - leftMark) * 2 + 1);
         
        return ans; 
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 25; string Arr2[] = {"###################################################", "# # # # # # # # # # # # # # # # # # # # # # # # # #", "#         #         #         #         #         #", "#                   #                   #          ", "0                   10                  20         " }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, draw(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 981; int Arg1 = 990; string Arr2[] = {"###################", "# # # # # # # # # #", "        #         #", "                  #", "0                 9" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, draw(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 20; int Arg1 = 20; string Arr2[] = {"#", "#", "#", "#", "2" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, draw(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 31; int Arg1 = 38; string Arr2[] = {"###############", "# # # # # # # #", "        #      ", "               ", "               " }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, draw(Arg0, Arg1)); }

// END CUT HERE
};

// BEGIN CUT HERE
int main() {
    TapeMeasure ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
