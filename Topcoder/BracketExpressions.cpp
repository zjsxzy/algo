#line 2 "BracketExpressions.cpp"
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


class BracketExpressions {
    public:
    string ifPossible(string expression) {
		if (solve(expression, 0)) return "possible";
		else return "impossible";
    }
	
	bool solve(string st, int pos) {
		if (pos == st.size()) {
			return correctBracket(st);
		}
		if (st[pos] != 'X') return solve(st, pos + 1);
		bool flag = false;
		st[pos] = '(';
		if (solve(st, pos + 1)) flag = true;
		st[pos] = ')';
		if (solve(st, pos + 1)) flag = true;
		st[pos] = '[';
		if (solve(st, pos + 1)) flag = true;
		st[pos] = ']';
		if (solve(st, pos + 1)) flag = true;
		st[pos] = '{';
		if (solve(st, pos + 1)) flag = true;
		st[pos] = '}';
		if (solve(st, pos + 1)) flag = true;
		return flag;
	}
	
	bool correctBracket(string exp) {
		stack<char> st;
		map<char, char> mp;
		mp[')'] = '('; mp[']'] = '['; mp['}'] = '{';
		for (int i = 0; i < exp.size(); i++) {
			char ch = exp[i];
			if (ch == '(' || ch == '[' || ch == '{') {
				st.push(ch);
			} else {
				if (st.size() == 0 || st.top() != mp[ch]) {
					return false;
				} else {
					st.pop();
				}
			}
		}
		return st.empty();
	}
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "([]{})"; string Arg1 = "possible"; verify_case(0, Arg1, ifPossible(Arg0)); }
	void test_case_1() { string Arg0 = "(())[]"; string Arg1 = "possible"; verify_case(1, Arg1, ifPossible(Arg0)); }
	void test_case_2() { string Arg0 = "({])"; string Arg1 = "impossible"; verify_case(2, Arg1, ifPossible(Arg0)); }
	void test_case_3() { string Arg0 = "[]X"; string Arg1 = "impossible"; verify_case(3, Arg1, ifPossible(Arg0)); }
	void test_case_4() { string Arg0 = "([]X()[()]XX}[])X{{}}]"; string Arg1 = "possible"; verify_case(4, Arg1, ifPossible(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    BracketExpressions ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
