#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int dp[105][10500];

class FeedADrake {
    public:
    int feed(int stomach, vector <int> cakes, int excess) {
        int ex = 0;
        sort(cakes.begin(), cakes.end());
        while (!cakes.empty() && excess > 0) {
            ex += cakes.back();
            cakes.pop_back();
            excess--;
        }
        if (excess) return ex;
        memset(dp, 0, sizeof(dp));
        int n = cakes.size();
        dp[0][0] = 1;
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < stomach; j++) {
                if (!dp[i][j]) continue;
                dp[i + 1][j] |= dp[i][j];
                if (j + cakes[i] < stomach) {
                    dp[i + 1][j + cakes[i]] |= dp[i][j];
                } else {
                    res = max(res, j + cakes[i]);
                }
            }
        }
        for (int j = 0; j <= stomach; j++) {
            if (!dp[n][j]) continue;
            res = max(res, j);
        }
        return res + ex;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1234; int Arr1[] = {10, 20, 30, 40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 100; verify_case(0, Arg3, feed(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 100; int Arr1[] = {100, 100, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 100; verify_case(1, Arg3, feed(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 101; int Arr1[] = {100, 100, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 200; verify_case(2, Arg3, feed(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 101; int Arr1[] = {100, 100, 100, 100, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 400; verify_case(3, Arg3, feed(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 4700; int Arr1[] = {1000, 8000, 2000, 5000, 3000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 12000; verify_case(4, Arg3, feed(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 100; int Arr1[] = {100001, 100002, 100003}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 200005; verify_case(5, Arg3, feed(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 1539; int Arr1[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; int Arg3 = 16; verify_case(6, Arg3, feed(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  FeedADrake ___test;
  ___test.run_test(-1);
  return 0;
}
// END CUT HERE
