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

const int MAX = 31;
long long dp[MAX + 1][2][2][2];

class LittleElephantAndXor {
public:
	vector<int> dA, dB, dC;

	vector<int> getBit(int x) {
		vector<int> bit(MAX);
		for (int i = 0; i < MAX; i++) {
			bit[i] = (x & (1 << i)) != 0;
		}
		return bit;
	}

	long long rec(int pos, int eqA, int eqB, int eqC) {
		if (dp[pos][eqA][eqB][eqC] != -1) return dp[pos][eqA][eqB][eqC];
		long long & res = dp[pos][eqA][eqB][eqC];
		res = 0;
		if (pos == 0) return res = 1;
		for (int x = 0; x < 2; x++)
			for (int y = 0; y < 2; y++) {
				int z = x ^ y;
				if ((!eqA || x <= dA[pos - 1]) && (!eqB || y <= dB[pos - 1]) && (!eqC || z <= dC[pos - 1])) {
					res += rec(pos - 1, eqA && x == dA[pos - 1], eqB && y == dB[pos - 1], eqC && z == dC[pos - 1]);
				}
			}
		return res;
	}

    long long getNumber (int A, int B, int C) {
		dA = getBit(A); dB = getBit(B); dC = getBit(C);
		memset(dp, -1, sizeof(dp));
		LL res = rec(MAX, 1, 1, 1);
		return res;
    }


    
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; long long Arg3 = 5LL; verify_case(0, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 7; int Arg2 = 3; long long Arg3 = 20LL; verify_case(1, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 5; long long Arg3 = 57LL; verify_case(2, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 774; int Arg1 = 477; int Arg2 = 447; long long Arg3 = 214144LL; verify_case(3, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1000000000; int Arg1 = 1000000000; int Arg2 = 500000000; long long Arg3 = 468566946385621507LL; verify_case(4, Arg3, getNumber(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    LittleElephantAndXor ___test;
    for (int i = 0; i < 6; i++)
        ___test.run_test(i);
    return 0;
}
// END CUT HERE
