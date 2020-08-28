#line 2 "NamingConvention.cpp"
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


class NamingConvention {
    public:
    string toCamelCase(string variableName) {
		int n = variableName.size();
		string res = "", cur = "";
		bool flag = false;
		for (int i = 0; i < n; i++) {
			if (variableName[i] == '_') {
				if (flag) cur[0] = toupper(cur[0]);
				res += cur;
				cur = "";
				flag = true;
			} else {
				cur += variableName[i];
			}
		}
		if (flag) cur[0] = toupper(cur[0]);
		res += cur;
		return res;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "sum_of_two_numbers"; string Arg1 = "sumOfTwoNumbers"; verify_case(0, Arg1, toCamelCase(Arg0)); }
	void test_case_1() { string Arg0 = "variable"; string Arg1 = "variable"; verify_case(1, Arg1, toCamelCase(Arg0)); }
	void test_case_2() { string Arg0 = "t_o_p_c_o_d_e_r"; string Arg1 = "tOPCODER"; verify_case(2, Arg1, toCamelCase(Arg0)); }
	void test_case_3() { string Arg0 = "the_variable_name_can_be_very_long_like_this"; string Arg1 = "theVariableNameCanBeVeryLongLikeThis"; verify_case(3, Arg1, toCamelCase(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    NamingConvention ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
