#line 2 "HappyLetterDiv1.cpp"
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


class HappyLetterDiv1 {
    public:
    string getHappyLetters(string letters) {
		int n = letters.size();
		map<char, int> mp;
		for (int i = 0; i < n; i++)
			mp[letters[i]]++;
		set<int> st;
		FOREACH(it, mp) {
			int cnt = it->second;
			int temp = n - it->second, mx = -1;
			FOREACH(it2, mp) {
				if (it->first == it2->first) continue;
				if (it2->second > mx) mx = it2->second;
			}
			if (temp % 2 == 1)
				temp = max(1, mx - (temp - mx));
			else
				temp = max(0, mx - (temp - mx));
			if (cnt > temp) st.insert(it->first);
		}
		string ret;
		FOREACH(it, st) {
			ret += *it;
		}
		return ret;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aabbacccc"; string Arg1 = "abc"; verify_case(0, Arg1, getHappyLetters(Arg0)); }
	void test_case_1() { string Arg0 = "aaaaaaaccdd"; string Arg1 = "a"; verify_case(1, Arg1, getHappyLetters(Arg0)); }
	void test_case_2() { string Arg0 = "ddabccadb"; string Arg1 = "abcd"; verify_case(2, Arg1, getHappyLetters(Arg0)); }
	void test_case_3() { string Arg0 = "aaabbb"; string Arg1 = ""; verify_case(3, Arg1, getHappyLetters(Arg0)); }
	void test_case_4() { string Arg0 = "rdokcogscosn"; string Arg1 = "cos"; verify_case(4, Arg1, getHappyLetters(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    HappyLetterDiv1 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
