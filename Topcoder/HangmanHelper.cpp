#line 2 "HangmanHelper.cpp"
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class HangmanHelper {
	public:
	string show(string secretWord, string lettersGuessed) {
        set<char> st;
        for (auto &c : lettersGuessed) {
            st.insert(c);
        }
        string res = "";
        for (auto &c : secretWord) {
            if (st.find(c) == st.end()) {
                res += "_";
            } else {
                res += c;
            }
        }
        return res;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "SECRET"; string Arg1 = ""; string Arg2 = "______"; verify_case(0, Arg2, show(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "SECRET"; string Arg1 = "CAE"; string Arg2 = "_EC_E_"; verify_case(1, Arg2, show(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "REVEALED"; string Arg1 = "QWERTYUIOPASDFGHJKLZXCVBNM"; string Arg2 = "REVEALED"; verify_case(2, Arg2, show(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ALONGEREXAMPLE"; string Arg1 = "SOMETHING"; string Arg2 = "__ONGE_E__M__E"; verify_case(3, Arg2, show(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	HangmanHelper ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
