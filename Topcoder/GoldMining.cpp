#line 2 "GoldMining.cpp"
#include <map>
#include <set>
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
#include <algorithm>
using namespace std;

class GoldMining {
    public:
    long long maxProfit(long long goldInGround, long long miningTime, long long hiringCost) {
        if (goldInGround <= miningTime) {
            return goldInGround;
        }
        long long res = miningTime;
        long long cur_gold = 0, cur_workers = 1;
        for (int i = 0; i < miningTime; i++) {
            long long max_hire = min(cur_gold / hiringCost, goldInGround / (miningTime - i) - cur_workers);
            cur_workers += max_hire;
            cur_gold -= max_hire * hiringCost;
            res = max(res, cur_gold + cur_workers * (miningTime - i));
            cur_gold += min(cur_workers, goldInGround);
            goldInGround -= min(cur_workers, goldInGround);
        }
        return res;
    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 470000LL; long long Arg1 = 1000000LL; long long Arg2 = 50LL; long long Arg3 = 470000LL; verify_case(0, Arg3, maxProfit(Arg0, Arg1, Arg2)); }
	void test_case_1() { long long Arg0 = 470000LL; long long Arg1 = 100000LL; long long Arg2 = 1234567890123456LL; long long Arg3 = 100000LL; verify_case(1, Arg3, maxProfit(Arg0, Arg1, Arg2)); }
	void test_case_2() { long long Arg0 = 470000LL; long long Arg1 = 100000LL; long long Arg2 = 57000LL; long long Arg3 = 100000LL; verify_case(2, Arg3, maxProfit(Arg0, Arg1, Arg2)); }
	void test_case_3() { long long Arg0 = 470000LL; long long Arg1 = 100000LL; long long Arg2 = 42000LL; long long Arg3 = 116000LL; verify_case(3, Arg3, maxProfit(Arg0, Arg1, Arg2)); }
	void test_case_4() { long long Arg0 = 567890LL; long long Arg1 = 4LL; long long Arg2 = 1LL; long long Arg3 = 8LL; verify_case(4, Arg3, maxProfit(Arg0, Arg1, Arg2)); }
	void test_case_5() { long long Arg0 = 234567LL; long long Arg1 = 47LL; long long Arg2 = 10LL; long long Arg3 = 215LL; verify_case(5, Arg3, maxProfit(Arg0, Arg1, Arg2)); }
	void test_case_6() { long long Arg0 = 300LL; long long Arg1 = 47LL; long long Arg2 = 10LL; long long Arg3 = 190LL; verify_case(6, Arg3, maxProfit(Arg0, Arg1, Arg2)); }
	void test_case_7() { long long Arg0 = 987654321098765432LL; long long Arg1 = 100LL; long long Arg2 = 3LL; long long Arg3 = 2731288513472LL; verify_case(7, Arg3, maxProfit(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
    GoldMining test;
    test.run_test(-1);
    return 0;
}
// END CUT HERE
