#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Stringversions {
	public:
	string create(int L, int N) {
        string res;
        int n = N;
        res += "z";
        vector<int> cnt(26);
        cnt[25]++;
        for (int i = 2; i <= L; i++) {
            int sum = 0, j;
            for (j = 25; j >= 0; j--) {
                if (cnt[j] == 0) {
                    break;
                } else {
                    if (sum + cnt[j] > n) {
                        break;
                    } else {
                        sum += cnt[j];
                    }
                }
            }
            if (j < 0) return "";
            res += (char)('a' + j);
            cnt[j]++;
            n -= sum;
            if (n == 0) break;
        }
        if (n > 0) return "";
        while (res.size() < L) {
            res += "z";
        }
        /*
        int t = 0;
        for (int i = 0; i < L; i++) {
            for (int j = i + 1; j < L; j++) {
                if (res[i] > res[j]) t++;
            }
        }
        cout << t << endl;
        */
        return res;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 1; string Arg2 = "hello"; verify_case(0, Arg2, create(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 0; string Arg2 = "xxxxxxx"; verify_case(1, Arg2, create(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 21; string Arg2 = "sponged"; verify_case(2, Arg2, create(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 27; int Arg1 = 351; string Arg2 = ""; verify_case(3, Arg2, create(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 25; int Arg1 = 152; string Arg2 = "topcoderroundonesubroundb"; verify_case(4, Arg2, create(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	Stringversions ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
