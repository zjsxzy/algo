#line 2 "LunchLine.cpp"
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class LunchLine {
	public:
	long long simulate(int N, int M, int A, int B, int C, int D, int E) {
        set<pair<int, int>> line;
        vector<int> t(N);
        for (int i = 0; i < N; i++) {
            line.insert(make_pair(-1, i));
            t[i] = -1;
        }
        vector<int> k(M);
        if (M > 0) {
            k[0] = A;
            k[1] = B;
            for (int i = 2; i < M; i++) {
                LL temp = ((LL)C * k[i - 1] + (LL)D * k[i - 2] + (LL)E);
                k[i] = temp % N;
            }
        }
        for (int i = 0; i < M; i++) {
            auto it = line.find(make_pair(t[k[i]], k[i]));
            line.erase(it);
            line.insert(make_pair(i, k[i]));
            t[k[i]] = i;
        }
        vector<LL> f(N);
        int iter = 0;
        for (auto &x: line) {
            f[x.second] = iter;
            iter++;
        }
        LL res = 0;
        for (int i = 0; i < N; i++) {
            res += (LL)i * f[i];
        }
        return res;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 250000; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 0; long long Arg7 = 5208302083375000LL; verify_case(0, Arg7, simulate(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 5; int Arg2 = 2; int Arg3 = 3; int Arg4 = 1; int Arg5 = 0; int Arg6 = 1; long long Arg7 = 225LL; verify_case(1, Arg7, simulate(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 5; int Arg2 = 2; int Arg3 = 4; int Arg4 = 1; int Arg5 = 0; int Arg6 = 2; long long Arg7 = 210LL; verify_case(2, Arg7, simulate(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 100000; int Arg2 = 4; int Arg3 = 7; int Arg4 = 0; int Arg5 = 0; int Arg6 = 3; long long Arg7 = 249LL; verify_case(3, Arg7, simulate(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_4() { int Arg0 = 11; int Arg1 = 30; int Arg2 = 4; int Arg3 = 7; int Arg4 = 1; int Arg5 = 2; int Arg6 = 3; long long Arg7 = 229LL; verify_case(4, Arg7, simulate(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	LunchLine ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
