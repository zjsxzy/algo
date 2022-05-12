#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class SnookerScoring {
	public:
    vector<int> part1;
	vector <int> scoreN(int N, int R, int C) {
        if (N == 1) return {1};
        vector<vector<int>> dp(R + 1, vector<int>(R * (C + 1) + 1, 0));
        vector<vector<int>> pre(R + 1, vector<int>(R * (C + 1) + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < R * (C + 1); j++) {
                if (dp[i][j]) {
                    for (int k = 2; k <= C + 1; k++) {
                        if (j + k <= R * (C + 1)) {
                            dp[i + 1][j + k] |= dp[i][j];
                            pre[i + 1][j + k] = j;
                        }
                    }
                }
            }
        }

        for (int i = 0; i <= R; i++) {
            for (int j = 0; j <= R * (C + 1); j++) {
                if (!dp[i][j]) continue;
                if (i + j == N) {
                    vector<int> res;
                    int a = i, b = N - i;
                    while (a) {
                        res.push_back(1);
                        res.push_back(b - pre[a][b]);
                        b = pre[a][b];
                        a--;
                    }
                    return res;
                }
                int s = 0;
                for (int k = 0; k < C; k++) {
                    s += 2 + k;
                    if (i + j + s == N) {
                        vector<int> res;
                        int a = i, b = N - i - s;
                        while (a) {
                            res.push_back(1);
                            res.push_back(b - pre[a][b]);
                            b = pre[a][b];
                            a--;
                        }
                        for (int kk = 0; kk <= k; kk++) {
                            res.push_back(2 + kk);
                        }
                        return res;
                    }
                }
            }
        }
        return {};
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 51; int Arg1 = 15; int Arg2 = 6; int Arr3[] = {1, 7, 1, 7, 1, 7, 2, 3, 4, 5, 6, 7 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, scoreN(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 12; int Arg1 = 15; int Arg2 = 6; int Arr3[] = {3, 4, 5 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, scoreN(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 17; int Arg1 = 15; int Arg2 = 6; int Arr3[] = {1, 2, 2, 3, 4, 5 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, scoreN(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 16; int Arg1 = 15; int Arg2 = 6; int Arr3[] = {1, 7, 1, 6, 1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, scoreN(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 45; int Arg1 = 10; int Arg2 = 2; int Arr3[] = {1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 2, 3 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, scoreN(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	SnookerScoring ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
