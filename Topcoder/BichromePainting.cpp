#line 2 "BichromePainting.cpp"
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

// const int MAXN = 22;
class BichromePainting {
    public:
    string isThatPossible(vector <string> board, int k) {
		int n = board.size();
		while (true) {
			bool found = false;
			for (int i = 0; i + k <= n; i++) {
				for (int j = 0; j + k <= n; j++) {
					// cout << i << " " << j << endl;
					bool black = false, white = false;
					for (int x = 0; x < k; x++) {
						for (int y = 0; y < k; y++) {
							if (board[i + x][j + y] == 'W') white = true;
							if (board[i + x][j + y] == 'B') black = true;
						}
					}
					if (black != white) {
						found = true;
						// cout << i << " " << j << endl;
						for (int x = 0; x < k; x++) {
							for (int y = 0; y < k; y++) {
								board[i + x][j + y] = '?';
							}
						}
					}
				}
			}
			if (!found) break;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 'B') return "Impossible";
			}
		}
		return "Possible";
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"BBBW",
 "BWWW",
 "BWWW",
 "WWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; string Arg2 = "Possible"; verify_case(0, Arg2, isThatPossible(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"BW",
 "WB"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "Impossible"; verify_case(1, Arg2, isThatPossible(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"BWBWBB",
 "WBWBBB",
 "BWBWBB",
 "WBWBBB",
 "BBBBBB",
 "BBBBBB"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "Possible"; verify_case(2, Arg2, isThatPossible(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "BBBBBB"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "Impossible"; verify_case(3, Arg2, isThatPossible(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "BBBBBB"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; string Arg2 = "Possible"; verify_case(4, Arg2, isThatPossible(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"BB",
 "BB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "Possible"; verify_case(5, Arg2, isThatPossible(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    BichromePainting ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
