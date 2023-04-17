#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class ARight {
    public:
    string modify(string S, int K) {
        for (int i = S.size() - 1 - K; i >= 0; i--) {
            if (S[i] == 'a') {
                for (int j = i, p = K; p > 0; p--, j++) {
                    swap(S[j], S[j + 1]);
                }
            }
        }
        return S;
    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "topcoder"; int Arg1 = 3; string Arg2 = "topcoder"; verify_case(0, Arg2, modify(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "bananas"; int Arg1 = 1; string Arg2 = "bnanasa"; verify_case(1, Arg2, modify(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "aaaaabbbbb"; int Arg1 = 5; string Arg2 = "bbbbbaaaaa"; verify_case(2, Arg2, modify(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "abracadabrahocuspocus"; int Arg1 = 6; string Arg2 = "brcdbrahoacauaspaocus"; verify_case(3, Arg2, modify(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "aardvark"; int Arg1 = 1; string Arg2 = "raadvrak"; verify_case(4, Arg2, modify(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "aardvark"; int Arg1 = 2; string Arg2 = "rdaavrka"; verify_case(5, Arg2, modify(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    ARight ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
