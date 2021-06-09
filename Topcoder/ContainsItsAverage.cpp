#line 2 "ContainsItsAverage.cpp"
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class ContainsItsAverage {
	public:
	vector <int> missing(vector <int> seq) {
        int n = seq.size() + 1;
        int sum = 0;
        for (auto &x : seq) {
            sum += x;
        }

        set<int> res;
        if (sum % (n - 1) == 0) {
            res.insert(sum / (n - 1));
        }
        for (auto &x : seq) {
            res.insert(x * n - sum);
        }
        vector<int> ret;
        for (auto &x : res) {
            ret.push_back(x);
        }
        return ret;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, missing(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 10, 1000, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1106, -1061, -611, 3889 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, missing(Arg0)); }
	void test_case_2() { int Arr0[] = {500000, 400000, 200000, 100000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-700000, -200000, 300000, 800000, 1300000 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, missing(Arg0)); }
	void test_case_3() { int Arr0[] = {47}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {47 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, missing(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	ContainsItsAverage ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
