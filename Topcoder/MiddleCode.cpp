#include <map>
#include <set>
#include <list>
#include <list>
#include <cmath>
#include <queue>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class MiddleCode {
public:
    string encode (string s) {
		string t = "";
		while (s.size()) {
			if (s.size() & 1) {
				t += s[s.size() / 2];
				s.erase(s.begin() + s.size() / 2);
			} else {
				int mid = s.size() / 2;
				char c1 = s[mid - 1], c2 = s[mid];
				if (c1 < c2) {
					t += c1;
					s.erase(s.begin() + mid - 1);
				} else {
					t += c2;
					s.erase(s.begin() + mid);
				}
			}
		}
		return t;
    }


    
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "word"; string Arg1 = "ordw"; verify_case(0, Arg1, encode(Arg0)); }
	void test_case_1() { string Arg0 = "aaaaa"; string Arg1 = "aaaaa"; verify_case(1, Arg1, encode(Arg0)); }
	void test_case_2() { string Arg0 = "abacaba"; string Arg1 = "caabbaa"; verify_case(2, Arg1, encode(Arg0)); }
	void test_case_3() { string Arg0 = "shjegr"; string Arg1 = "ejghrs"; verify_case(3, Arg1, encode(Arg0)); }
	void test_case_4() { string Arg0 = "adafaaaadafawafwfasdaa"; string Arg1 = "afawadafawafaafsadadaa"; verify_case(4, Arg1, encode(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    MiddleCode ___test;
    for (int i = 0; i < 6; i++)
        ___test.run_test(i);
    return 0;
}
// END CUT HERE
