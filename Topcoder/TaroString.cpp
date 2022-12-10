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

class TaroString {
public:
    string getAnswer (string S) {
		int n = S.size();
		string str = "";
		for (int i = 0; i < n; i++)
			if (S[i] == 'A' || S[i] == 'C' || S[i] == 'T') str += S[i];
		//str.resize(unique(str.begin(), str.end()) - str.begin());
		return str == "CAT" ? "Possible" : "Impossible";
    }


    
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "XCYAZTX"; string Arg1 = "Possible"; verify_case(0, Arg1, getAnswer(Arg0)); }
	void test_case_1() { string Arg0 = "CTA"; string Arg1 = "Impossible"; verify_case(1, Arg1, getAnswer(Arg0)); }
	void test_case_2() { string Arg0 = "ACBBAT"; string Arg1 = "Impossible"; verify_case(2, Arg1, getAnswer(Arg0)); }
	void test_case_3() { string Arg0 = "SGHDJHFIOPUFUHCHIOJBHAUINUIT"; string Arg1 = "Possible"; verify_case(3, Arg1, getAnswer(Arg0)); }
	void test_case_4() { string Arg0 = "CCCATT"; string Arg1 = "Impossible"; verify_case(4, Arg1, getAnswer(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    TaroString ___test;
    for (int i = 0; i < 6; i++)
        ___test.run_test(i);
    return 0;
}
// END CUT HERE
