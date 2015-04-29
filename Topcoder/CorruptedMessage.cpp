#line 2 "CorruptedMessage.cpp"
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


class CorruptedMessage {
    public:
    string reconstructMessage(string s, int k) {
		int n = s.size();
		vector<int> d(26);
		for (int i = 0; i < n; i++) {
			d[s[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if (d[i] + k == n) {
				string res = "";
				for (int j = 0; j < n; j++) {
					res += (char)('a' + i);
				}
				return res;
			}
		}
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "hello"; int Arg1 = 3; string Arg2 = "lllll"; verify_case(0, Arg2, reconstructMessage(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "abc"; int Arg1 = 3; string Arg2 = "ddd"; verify_case(1, Arg2, reconstructMessage(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "wwwwwwwwwwwwwwwwww"; int Arg1 = 0; string Arg2 = "wwwwwwwwwwwwwwwwww"; verify_case(2, Arg2, reconstructMessage(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ababba"; int Arg1 = 3; string Arg2 = "aaaaaa"; verify_case(3, Arg2, reconstructMessage(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "zoztxtoxytyt"; int Arg1 = 10; string Arg2 = "oooooooooooo"; verify_case(4, Arg2, reconstructMessage(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "jlmnmiunaxzywed"; int Arg1 = 13; string Arg2 = "mmmmmmmmmmmmmmm"; verify_case(5, Arg2, reconstructMessage(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    CorruptedMessage ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
