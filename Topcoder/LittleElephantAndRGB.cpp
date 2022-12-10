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

const int maxn = 2555;
int sumL[maxn][maxn], sumR[maxn][maxn];
LL dp[maxn];
class LittleElephantAndRGB {
public:
	string str;
	int N, K;
    long long getNumber (vector <string> list, int minGreen) {
		memset(sumL, 0, sizeof(sumL));
		memset(sumR, 0, sizeof(sumR));
		memset(dp, 0, sizeof(dp));
		K = minGreen;
		str = "";
		for (int i = 0; i < list.size(); i++) {
			str += list[i];
		}
		N = SZ(str);
		calc(sumL);
		reverse(str.begin(), str.end());
		calc(sumR);

		LL res = 0;
		for (int i = 1; i < N; i++) {
			int cnt = 0;
			for (int j = 0; j <= K; j++) {
				dp[j] += sumL[i][j];
				cnt += sumR[N - i][K - j];
				res += (LL)dp[j] * cnt;
			}
		}
		return res;
    }

	void calc(int sum[maxn][maxn]) {
		int cur = 0, last = -1;
		for (int i = 0; i < N; i++) {
			if (str[i] == 'G') cur++;
			else cur = 0;
			if (cur > K) cur = K;
			if (cur == K) last = i - K + 1;
			for (int j = 1; j <= i + 1; j++) {
				if (i - j + 1 <= last) sum[i + 1][K]++;
				else sum[i + 1][min(j, cur)]++;
			}
		}
	}


    
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"GRG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; long long Arg2 = 1LL; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"GG", "GG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; long long Arg2 = 9LL; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"GRBGRBBRG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; long long Arg2 = 11LL; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"RRBRBBRRR", "R", "B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; long long Arg2 = 0LL; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"GRGGGRBRGG", "GGGGGGGG", "BRGRBRB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; long long Arg2 = 12430LL; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    LittleElephantAndRGB ___test;
    for (int i = 0; i < 6; i++)
        ___test.run_test(i);
    return 0;
}
// END CUT HERE
