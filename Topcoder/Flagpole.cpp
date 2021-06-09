#line 2 "Flagpole.cpp"
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Flagpole {
	public:
	long long build(vector <int> segments, long long LO, long long HI) {
        int n = segments.size();
        int half = n / 2;
        int ls = half, rs = n - half;
        vector<LL> lsum(1 << ls, 0);
        for (int i = 0; i < (1 << ls); i++) {
            for (int j = 0; j < ls; j++) {
                if ((i >> j) & 1) {
                    lsum[i] = lsum[i ^ (1 << j)] + segments[j];
                }
            }
        }
        vector<LL> rsum(1 << rs, 0);
        for (int i = 0; i < (1 << rs); i++) {
            for (int j = 0; j < rs; j++) {
                if ((i >> j) & 1) {
                    rsum[i] = rsum[i ^ (1 << j)] + segments[half + j];
                }
            }
        }

        sort(lsum.begin(), lsum.end());
        sort(rsum.begin(), rsum.end());
        LL res = 0;
        for (int i = 0; i < lsum.size(); i++) {
            LL x = LO - lsum[i];
            auto lit = upper_bound(rsum.begin(), rsum.end(), x);

            x = HI - lsum[i];
            auto rit = upper_bound(rsum.begin(), rsum.end(), x);
            res += (LL)(rit - lit);
        }
        return res;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {10, 10, 10, 10, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 9LL; long long Arg2 = 49LL; long long Arg3 = 30LL; verify_case(0, Arg3, build(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {10, 10, 10, 10, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 30LL; long long Arg2 = 39LL; long long Arg3 = 0LL; verify_case(1, Arg3, build(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 2, 4, 8, 16, 32, 64, 128}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 47LL; long long Arg2 = 100LL; long long Arg3 = 53LL; verify_case(2, Arg3, build(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {50, 10, 40, 30, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 45LL; long long Arg2 = 63LL; long long Arg3 = 6LL; verify_case(3, Arg3, build(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	Flagpole ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
