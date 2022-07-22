#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


class AddFlowers {
    public:
    vector <string> add(vector <string> lawn) {
        int n = lawn.size(), m = lawn[0].size();
        vector<pair<int, int>> p;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (lawn[i][j] == 'F') p.emplace_back(i, j);
            }
        }
        for (auto e: p) {
            int x = e.first, y = e.second;
            if (x == n - 1) x--;
            if (y == m - 1) y--;
            lawn[x][y] = lawn[x + 1][y] = lawn[x][y + 1] = lawn[x + 1][y + 1] = 'F';
        }
        return lawn;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"..........",
 "...FFFF...",
 "..FF......",
 "..F...F...",
 "..FFFFF...",
 ".........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..........", "...FFFF...", "..FF..F...", "..F...F...", "..FFFFF...", ".........." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, add(Arg0)); }
	void test_case_1() { string Arr0[] = {"F.F.F.",
 ".F.F.F",
 "F.F.F."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"FFFFFF", "FFFFFF", "FFFFFF" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, add(Arg0)); }
	void test_case_2() { string Arr0[] = {"..........",
 "...FFFF...",
 "..FF.FFF..",
 "..F.F.F...",
 "..FF.FF...",
 "....F....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..........", "...FFFFF..", "..FF.FFF..", "..FFF.FF..", "..FFFFF...", "...FF....." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, add(Arg0)); }
	void test_case_3() { string Arr0[] = {"......",
 "......"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"......", "......" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, add(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  AddFlowers ___test;
  ___test.run_test(-1);
  return 0;
}
// END CUT HERE
