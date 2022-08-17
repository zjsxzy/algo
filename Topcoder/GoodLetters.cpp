#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class GoodLetters {
	public:
	string construct(string good, int N, int G) {
        int n = 26;
        vector<int> vst(n, 0);
        for (auto x: good) vst[x - 'A'] = 1;
        string res;
        int tot = 0;
        for (int i = 0; i < n && tot < G; i++) {
            if (vst[i]) {
                tot++;
                res += (char)('A' + i);
            }
        }
        if (tot < G) return "";

        for (int i = 0; i < n && tot < N; i++) {
            if (vst[i]) continue;
            res += (char)('A' + i);
            tot++;
        }
        if (tot < N) return "";
        return res;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AEIOU"; int Arg1 = 10; int Arg2 = 3; string Arg3 = "BLUEPRINTS"; verify_case(0, Arg3, construct(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "AAEEIOUIOUIOU"; int Arg1 = 10; int Arg2 = 3; string Arg3 = "BLUEPRINTS"; verify_case(1, Arg3, construct(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = ""; int Arg1 = 7; int Arg2 = 1; string Arg3 = ""; verify_case(2, Arg3, construct(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "EEEEE"; int Arg1 = 5; int Arg2 = 2; string Arg3 = ""; verify_case(3, Arg3, construct(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = ""; int Arg1 = 3; int Arg2 = 0; string Arg3 = "ABC"; verify_case(4, Arg3, construct(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	GoodLetters ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
