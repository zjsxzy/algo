#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class PlugStuffIn {
	public:
	vector <int> plug(vector <int> gadgets) {
        int n = gadgets.size();
        vector<int> used = gadgets;
        int mx = 0, idx;
        for (int i = 0; i < n; i++) {
            if (gadgets[i] > mx) {
                mx = gadgets[i];
                idx = i;
            }
        }
        vector<int> ans(n, -1);
        priority_queue<pair<int, int>> pq;
        if (mx > 0) {
            ans[idx] = n;
            pq.push({gadgets[idx], idx});
        } else {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (gadgets[i] == 0) {
                    ans[i] = n;
                    cnt++;
                    if (cnt > 1) return {};
                }
            }
            return ans;
        }

        for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++) {
            if (ans[i] == -1 && gadgets[i]) {
                if (!pq.empty()) {
                    auto p = pq.top(); pq.pop();
                    ans[i] = p.second;
                    if (p.first > 1) pq.push({p.first - 1, p.second});
                    pq.push({gadgets[i], i});
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (gadgets[i] == 0) {
                if (pq.empty()) return {};
                auto p = pq.top(); pq.pop();
                ans[i] = p.second;
                if (p.first > 1) pq.push({p.first - 1, p.second});
            }
        }
        return ans;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, plug(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 1, 0, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, -1, 4, -1, 6, -1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, plug(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 1, 0, 1, 1, 1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, plug(Arg0)); }
	void test_case_3() { int Arr0[] = {0, 0, 2, 0, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 4, 5, 4, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, plug(Arg0)); }
	void test_case_4() { int Arr0[] = {0, 3, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 2, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, plug(Arg0)); }
	void test_case_5() { int Arr0[] = {10, 20, 30, 40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, 1, -1, -1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, plug(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	PlugStuffIn ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
