#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class OneBattleship {
	public:
	vector <string> hit(vector <string> grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> cnt(3);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '.') cnt[(i + j) % 3]++;
            }
        }
        int mn = 0;
        for (int i = 0; i < 3; i++) {
            if (cnt[i] < cnt[mn]) mn = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '.' && (i + j) % 3 == mn) {
                    grid[i][j] = '*';
                }
            }
        }
        return grid;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"WW.WW",
 "WW.WW",
 ".....",
 "WW.WW",
 "WW.WW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"WW.WW", "WW.WW", "..*..", "WW.WW", "WW.WW" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, hit(Arg0)); }
	void test_case_1() { string Arr0[] = {".W......."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".W..*.*.." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, hit(Arg0)); }
	void test_case_2() { string Arr0[] = {"W.W.W.W.",
 ".W.W.W.W",
 "W.W.W.W.",
 ".W.W.W.W",
 "W.W.W.W.",
 "...W.W.W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"W.W.W.W.", ".W.W.W.W", "W.W.W.W.", ".W.W.W.W", "W*W.W.W.", "***W.W.W" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, hit(Arg0)); }
	void test_case_3() { string Arr0[] = {"...",
 ".W.",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..*", ".W.", "*.." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, hit(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	OneBattleship ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
