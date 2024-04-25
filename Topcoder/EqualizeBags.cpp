#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class EqualizeBags {
    public:
    string check(int N, vector <int> bags, int E) {
        int sum = 0;
        for (auto x: bags) sum += x;
        if (sum < E) return "impossible";
        if ((sum - E) % N != 0) return "impossible";
        int d = (sum - E) / N;
        for (auto x: bags) {
            if (x < d) return "impossible";
        }
        return "possible";
    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {5, 47, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 42; string Arg3 = "possible"; verify_case(0, Arg3, check(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {5, 47, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 43; string Arg3 = "impossible"; verify_case(1, Arg3, check(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {5, 47, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 43; string Arg3 = "possible"; verify_case(2, Arg3, check(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1; int Arr1[] = {47}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 42; string Arg3 = "possible"; verify_case(3, Arg3, check(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; int Arr1[] = {42}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 47; string Arg3 = "impossible"; verify_case(4, Arg3, check(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 5; int Arr1[] = {1001, 1005, 1002, 1004, 1003}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 200; string Arg3 = "possible"; verify_case(5, Arg3, check(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    EqualizeBags ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
