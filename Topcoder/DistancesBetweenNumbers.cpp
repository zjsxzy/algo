#line 2 "DistancesBetweenNumbers.cpp"
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class DistancesBetweenNumbers {
	public:
	long long count(int N, vector <int> Aprefix) {

        vector<int> A(N);
        int L = Aprefix.size();
        for (int i=0; i<L; ++i) A[i] = Aprefix[i];
        for (int i=L; i<N; ++i) A[i] = (A[i-1] * 1103515245LL + 12345LL) % (1LL << 31);

        LL res = 0;
        for (int k = 0; k < 32; k++) {
            vector<int> cnt(10);
            for (auto &x : A) {
                cnt[x % 10]++;
            }
            for (int i = 0; i < 10; i++) {
                for (int j = i + 1; j < 10; j++) {
                    res += (LL)cnt[i] * (LL)cnt[j];
                }
            }
            for (auto &x : A) {
                x /= 10;
            }
        }
        return res;

	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {47, 47, 47, 47}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {47, 47, 42, 47}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 3LL; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arr1[] = {1, 10, 100, 1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 12LL; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arr1[] = {1234567, 1234890}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 389LL; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	DistancesBetweenNumbers ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
