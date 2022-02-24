#line 2 "ExactRate.cpp"
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const LL mod = (1LL << 31);
class ExactRate {
    public:
    vector <int> getLongest(int N, int seed, int threshold, int S, int F) {
        vector<LL> s(N + 1);
        LL sd = seed;
        for (int i = 1; i <= N; i++) {
            sd = (sd * 1103515245 + 12345) % mod;
            s[i] = s[i - 1] + (sd > threshold);
        }
        int L = 0, R = 0;
        map<LL, int> mp;
        mp[0] = 0;
        for (LL i = 1; i <= N; i++) {
            LL val = s[i] * (S + F) - i * S;
            // cout << i << " " << val << " " << mp[val] << " " << mp.count(val) << endl;
            if (mp.count(val)) {
                if (i - mp[val] > R - L) {
                    L = mp[val];
                    R = i;
                }
            } else {
                mp[val] = i;
            }
        }
        return {L, R};
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 12; int Arg1 = 47; int Arg2 = 1012345678; int Arg3 = 1; int Arg4 = 2; int Arr5[] = {0, 6 }; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(0, Arg5, getLongest(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 12; int Arg1 = 47; int Arg2 = 1012345678; int Arg3 = 2; int Arg4 = 1; int Arr5[] = {2, 8 }; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(1, Arg5, getLongest(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 12; int Arg1 = 47; int Arg2 = 1012345678; int Arg3 = 7; int Arg4 = 11; int Arr5[] = {0, 0 }; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(2, Arg5, getLongest(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};


// BEGIN CUT HERE
int main() {
  ExactRate ___test;
  ___test.run_test(-1);
  return 0;
}
// END CUT HERE
