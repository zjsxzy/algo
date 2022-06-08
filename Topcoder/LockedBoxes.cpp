#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class LockedBoxes {
	public:
	vector <int> openAll(int N, vector <int> box, vector <int> key) {
        int m = box.size();
        int res = INT_MAX, state = 0;
        map<int, set<int>> mp;
        for (int i = 0; i < m; i++) {
            mp[box[i]].insert(key[i]);
        }
        for (int s = 0; s < (1 << N); s++) {
            int b = __builtin_popcount(s);
            if (b < res && check(N, s, mp)) {
                res = b;
                state = s;
            }
        }
        vector<int> ans;
        for (int i = 0; i < N; i++) {
            if (state >> i & 1) ans.push_back(i);
        }
        return ans;
	}

    bool check(int N, int st, map<int, set<int>>& mp) {
        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (st >> i & 1) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            if (mp.find(p) == mp.end()) continue;
            for (auto x: mp[p]) {
                if (!(st >> x & 1)) {
                    st |= (1 << x);
                    q.push(x);
                }
            }
        }
        return st == (1 << N) - 1;
    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 1, 2, 3 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, openAll(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {0, 1, 1, 1, 2, 2, 3, 3, 3, 3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 1, 1, 2, 2, 3, 3, 3, 3, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 1, 2, 3 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, openAll(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 6; int Arr1[] = {3, 1, 3, 0, 2, 4, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4, 3, 5, 1, 0, 4, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, openAll(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 6; int Arr1[] = {0, 1, 2, 3, 4, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 0, 3, 2, 5, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 2, 4 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, openAll(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	LockedBoxes ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
