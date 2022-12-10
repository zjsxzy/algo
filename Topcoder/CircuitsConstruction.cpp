#line 2 "CircuitsConstruction.cpp"
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


class CircuitsConstruction {
    public:
    int maximizeResistance(string circuit, vector <int> conductors) {
		str = circuit;
		idx = 0;
		int sz = dfs();
		sort(conductors.begin(), conductors.end());
		reverse(conductors.begin(), conductors.end());
		int ret = 0;
		for (int i = 0; i < sz; i++)
			ret += conductors[i];
		return ret;
    }
	
	int dfs() {
		if (idx == str.size()) return 0;
		int ret = 0;
		if (str[idx] == 'X') return 1;
		else if (str[idx] == 'A') {
			idx++;
			int a = dfs();
			idx++;
			int b = dfs();
			ret = a + b;
		} else if (str[idx] == 'B') {
			idx++;
			int a = dfs();
			idx++;
			int b = dfs();
			ret = max(a, b);
		}
		return ret;
	}
	
	int idx;
	string str;
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BXBXX"; int Arr1[] = {8, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(0, Arg2, maximizeResistance(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "AAXXAXAXX"; int Arr1[] = {1, 1, 2, 8, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 22; verify_case(1, Arg2, maximizeResistance(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "AXBXX"; int Arr1[] = {8, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 11; verify_case(2, Arg2, maximizeResistance(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "BAAXBXXBXAXXBBAXXBXXAAXXX"; int Arr1[] = {17, 7, 21, 102, 56, 72, 88, 15, 9, 192, 16, 8, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 454; verify_case(3, Arg2, maximizeResistance(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    CircuitsConstruction ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
