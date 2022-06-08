#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class RerollCheater {
	public:
	vector <int> reroll(vector <int> currentDice, vector <int> futureRolls) {
        int m = currentDice.size(), n = futureRolls.size();
        int sum = 0;
        for (auto x: currentDice) sum += x;
        int res = sum, index = 0;
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            int x = futureRolls[i - 1];
            int p = 0;
            for (int j = 1; j < m; j++) {
                if (currentDice[j] < currentDice[p]) p = j;
            }
            sum += x - currentDice[p];
            ans.push_back(p);
            if (sum > res) {
                res = sum;
                index = i;
            }
            currentDice[p] = x;
        }
        vector<int> out;
        for (int i = 0; i < index; i++) out.push_back(ans[i]);
        return out;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20, 20, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 4, 5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, reroll(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {4, 7, 13, 19}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 2, 3, 1, 4, 1, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, reroll(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {18, 11, 15, 12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 14, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, reroll(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	RerollCheater ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
