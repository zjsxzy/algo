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

const int MOD = 1000000007;
map<set<int>, int> dp[105];
class AlienAndSetDiv2 {
public:
	int N, K;

	int rec(int n, set<int> unmatched) {
		map<set<int>, int>::iterator it;
		it = dp[n].find(unmatched);
		if (it != dp[n].end()) {
			return it->second % MOD;
		}

		int res = 0;
		if (n == 2 * N + 1) {
			if (unmatched.size() == 0) {
				res = 1;
			}
		} else {
			set<int> newset;
			if (unmatched.size() == 0) {
				newset = unmatched;
				newset.insert(n);
				res = rec(n + 1, newset) * 2 % MOD;
			} else {
				int x = *unmatched.begin();
				// match n with x
				newset = unmatched;
				newset.erase(newset.begin());
				res += rec(n + 1, newset);
				res %= MOD;

				// add to the other set
				if (x != n - K) {	
					newset = unmatched;
					newset.insert(n);
					res += rec(n + 1, newset);
					res %= MOD;
				}
			}
		}
		return dp[n][unmatched] = res;
	}

    int getNumber (int N, int K) {
		for (int i = 0; i < 2 * N + 1; i++)
			dp[i].clear();
		this->N = N; this->K = K;
		set<int> unmatched;
		return rec(1, unmatched);
    }


    
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 4; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 8; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 44; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 184756; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    AlienAndSetDiv2 ___test;
    for (int i = 0; i < 6; i++)
        ___test.run_test(i);
    return 0;
}
// END CUT HERE
