#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class TwoLineMinesweeper {
	public:
        vector<string> ans;
        vector<int> cnt;
        int n;
	vector <string> solve(vector <int> firstLine) {
        n = firstLine.size();
        cnt = firstLine;
        ans.clear();
        dfs(0, "");
        sort(ans.begin(), ans.end());
        return ans;
	}

    void dfs(int p, string curr) {
        if (ans.size() == 50) return;
        if (p == n) {
            bool flag = true;
            for (int i = 0; i < n; i++) {
                int t = 0;
                for (int d = -1; d <= 1; d++) {
                    if (i + d >= 0 && i + d < n) {
                        t += (curr[i + d] == '*');
                    }
                }
                if (t != cnt[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans.push_back(curr);
        } else {
            if (cnt[p] == 0) dfs(p + 1, curr + "-");
            else if (cnt[p] == 1) {
                if (p - 1 >= 0 && curr[p - 1] == '*') dfs(p + 1, curr + "-");
                else {
                    dfs(p + 1, curr + "-");
                    dfs(p + 1, curr + "*");
                }
            } else if (cnt[p] == 2) {
                    if (p - 1 >= 0 && p - 2 >= 0 && cnt[p - 1] == '*' && cnt[p - 2] == '*') dfs(p + 1, curr + '-');
                    else {
                        dfs(p + 1, curr + "-");
                        dfs(p + 1, curr + "*");
                    }
                }
            } else if (cnt[p] == 3) dfs(p + 1, curr + "*");
        }
    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {0, 0, 0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"------" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { int Arr0[] = {0, 0, 1, 1, 1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"---*--" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"*-", "-*" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"*--*-", "-*--*"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, solve(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	TwoLineMinesweeper ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
