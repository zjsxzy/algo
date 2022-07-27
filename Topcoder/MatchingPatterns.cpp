#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct union_find{
    int N;
    vector<int> par, siz;
    union_find(int n) : N(n){
        par.resize(N);
        siz.resize(N, 1);
        for(int i=0; i<N; i++) par[i] = i;
    }
    int root(int X){
        if(par[X] == X) return X;
        return par[X] = root(par[X]);
    }
    bool same(int X, int Y){
        return root(X) == root(Y);
    }
    void unite(int X, int Y){
        X = root(X);
        Y = root(Y);
        if(X == Y) return;
        if(siz[Y] < siz[X]) std::swap(X, Y);
        par[X] = Y;
        siz[Y] += siz[X];
        siz[X] = 0;
    }
};

class MatchingPatterns {
	public:
	string solve(int N, vector <int> L, vector <string> patterns) {
        vector<int> shift(N + 1);
        shift[0] = 26;
        for (int i = 0; i < N; i++) {
            shift[i + 1] = shift[i] + L[i];
        }
        union_find uf(shift[N]);

        int sz = patterns.size();
        vector<vector<int>> a(sz);
        for (int i = 0; i < sz; i++) {
            for (auto c: patterns[i]) {
                if (c >= 'A' && c <= 'Z') {
                    int id = c - 'A';
                    for (int j = 0; j < L[id]; j++) {
                        a[i].push_back(shift[id] + j);
                    }
                } else {
                    int id = c - 'a';
                    a[i].push_back(id);
                }
            }
        }
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if (a[i].size() != a[j].size()) return "";
            }
        }

        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                for (int k = 0; k < a[i].size(); k++) {
                    uf.unite(a[i][k], a[j][k]);
                }
            }
        }

        for (int i = 0; i < 26; i++) {
            for (int j = i + 1; j < 26; j++) {
                if (uf.same(i, j)) return "";
            }
        }

        vector<string> word(N);
        for (int i = 0; i < N; i++) {
            word[i] = string(L[i], 'a');
            for (int j = 0; j < L[i]; j++) {
                for (int k = 0; k < 26; k++) {
                    if (uf.same(shift[i] + j, k)) {
                        word[i][j] = (char)('a' + k);
                        break;
                    }
                }
            }
        }
        string res;
        for (auto c: patterns[0]) {
            if (c >= 'A' && c <= 'Z') {
                int id = c - 'A';
                res += word[id];
            } else {
                res += c;
            }
        }
        return res;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"AAA"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "hehehe"; verify_case(0, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"ABxA", "BxxB"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "xxxxxxxx"; verify_case(1, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {2, 3, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"ABxA", "yCCB"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = ""; verify_case(2, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 3; int Arr1[] = {4, 5, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"A", "B", "C"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = ""; verify_case(3, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 4; int Arr1[] = {1, 2, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"ABCD", "DxAyzB"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "yzzzxyyzzz"; verify_case(4, Arg3, solve(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	MatchingPatterns ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
