#line 2 "RedAndGreen.cpp"
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
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class RedAndGreen
{
	public:
	int minPaints(string row)
	{
		int n = row.size();
		int ans = 100000;
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = i - 1; j >= 0; j--) 
				if (row[j] != 'R') cnt++;
			for (int j = i + 1; j < n; j++)
				if (row[j] != 'G') cnt++;
			ans = min(ans, cnt);
		}

		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RGRGR"; int Arg1 = 2; verify_case(0, Arg1, minPaints(Arg0)); }
	void test_case_1() { string Arg0 = "RRRGGGGG"; int Arg1 = 0; verify_case(1, Arg1, minPaints(Arg0)); }
	void test_case_2() { string Arg0 = "GGGGRRR"; int Arg1 = 3; verify_case(2, Arg1, minPaints(Arg0)); }
	void test_case_3() { string Arg0 = "RGRGRGRGRGRGRGRGR"; int Arg1 = 8; verify_case(3, Arg1, minPaints(Arg0)); }
	void test_case_4() { string Arg0 = "RRRGGGRGGGRGGRRRGGRRRGR"; int Arg1 = 9; verify_case(4, Arg1, minPaints(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE
int main()
{
	RedAndGreen ___test;
	for (int i = 0; i <= 5; i++)
	___test.run_test(i);
	return 0;
}
// END CUT HERE
