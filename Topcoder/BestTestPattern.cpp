#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class BestTestPattern {
    public:
    string solve(string correctAnswers, int maxLen) {
        int res = 0;
        string ans;
        for (int i = 1; i <= min(maxLen, (int)correctAnswers.size()); i++) {
            pair<int, string> t = calc(correctAnswers, i);
            if (t.first > res || (t.first == res && t.second < ans)) {
                res = t.first;
                ans = t.second;
            }
        }
        return ans;
    }

    pair<int, string> calc(string& s, int l) {
        vector<map<char, int>> cnt(l);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            cnt[i % l][s[i]]++;
        }
        string ans;
        int res = 0;
        for (int i = 0; i < l; i++) {
            char c = '$';
            int t = 0;
            for (auto [k, v]: cnt[i]) {
                if (v > t || (v == t && k < c)) {
                    c = k;
                    t = v;
                }
            }
            ans += c;
            res += t;
        }
        return make_pair(res, ans);
    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AACAAACBAACA"; int Arg1 = 5; string Arg2 = "AACA"; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "ABCABCAB"; int Arg1 = 3; string Arg2 = "ABC"; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "FCFBFAFDFEFCFBFEFDF"; int Arg1 = 4; string Arg2 = "FAFB"; verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "EEEEEEE"; int Arg1 = 3; string Arg2 = "E"; verify_case(3, Arg2, solve(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "AACAAACBAACA"; int Arg1 = 3; string Arg2 = "A"; verify_case(4, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    BestTestPattern ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
