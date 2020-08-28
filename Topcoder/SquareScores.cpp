#line 2 "SquareScores.cpp"
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


class SquareScores {
    public:
    double calcexpectation(vector <int> p, string s) {
		for (int i = p.size() + 1; i <= 26; i++) {
			p.PB(0);
		}
		double ret = 0.0;
		int n = s.size();
		for (char c = 'a'; c <= 'z'; c++) {
			for (int i = 0; i < n; i++) {
				double prob = 1.0;
				for (int j = i; j < n; j++) {
					if (s[j] != c && s[j] != '?') {
						break;
					} else if (s[j] == '?') {
						prob *= (double)p[c - 'a'] / 100;
					}
					// cout << char(c) << " " << i << " " << j << " " << prob << endl;
					ret += prob;
				}
			}
		}
		return ret;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 99}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aaaba"; double Arg2 = 8.0; verify_case(0, Arg2, calcexpectation(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {10, 20, 70}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aa?bbbb"; double Arg2 = 15.0; verify_case(1, Arg2, calcexpectation(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10, 20, 30, 40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "a??c?dc?b"; double Arg2 = 11.117; verify_case(2, Arg2, calcexpectation(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {25, 25, 21, 2, 2, 25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "a??b???????ff??e"; double Arg2 = 21.68512690712425; verify_case(3, Arg2, calcexpectation(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "??????????????????????????????"; double Arg2 = 31.16931963781721; verify_case(4, Arg2, calcexpectation(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {4, 3, 4, 3, 8, 2, 4, 3, 4, 4, 3, 2, 4, 4, 3, 4, 2, 4, 7, 6, 4, 4, 3, 4, 4, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "makigotapresentfromniko"; double Arg2 = 23.0; verify_case(5, Arg2, calcexpectation(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    SquareScores ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
