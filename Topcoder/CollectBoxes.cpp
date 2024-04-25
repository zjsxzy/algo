#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class CollectBoxes {
    public:
    long long collect(int N, vector <int> Bprefix, int seed, int blo, int bhi) {
        vector<LL> B(N);
        for (int i = 0; i < (int)Bprefix.size(); i++) {
            B[i] = Bprefix[i];
        }
        LL state = seed;
        LL spread = bhi - blo + 1;
        for (int i = (int)Bprefix.size(); i < N; i++) {
            state = (state * 1103515245 + 12345) % (1ll << 31);
            B[i] = blo + (state % spread);
        }
        for (auto x: B) cout << x << ' ';
        cout << endl;
        sort(B.begin(), B.end());
        LL res = 0;
        if (N & 1) {
            LL mid = B[N / 2];
            LL res = abs(mid);
            for (auto x: B) {
                res += abs(x - mid) * 2;
            }
            return res;
        } else {
            LL l = B[N / 2 - 1], r = B[N / 2];
            LL res = 0;
            if (l <= 0) {
                if (r >= 0) {
                    res += abs(r);
                    for (int i = 0; i < N / 2; i++) {
                        res += abs(B[i] - r);
                    }
                    for (int i = N / 2 + 1; i < N; i++) {
                        res += abs(B[i] - r);
                    }
                } else {
                    res += abs(l);
                    for (int i = 0; i < N / 2 - 1; i++) {
                        res += abs(B[i] - l);
                    }
                    for (int i = N / 2 + 1; i < N; i++) {
                        res += abs(B[i] - l);
                    }
                }
            } else {
                res += abs(r);
                for (int i = 0; i < N / 2 - 1; i++) {
                    res += abs(B[i] - r);
                }
                for (int i = N / 2 + 1; i < N; i++) {
                    res += abs(B[i] - r);
                }
            }
            return res;
        }
    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {11, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; long long Arg5 = 11LL; verify_case(0, Arg5, collect(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {10, 10, 11, 10, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; long long Arg5 = 12LL; verify_case(1, Arg5, collect(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 2; int Arr1[] = {-10, -11}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; long long Arg5 = 11LL; verify_case(2, Arg5, collect(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 2; int Arr1[] = {-47, 47}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; long long Arg5 = 141LL; verify_case(3, Arg5, collect(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 9; int Arr1[] = {10, 20, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 47; int Arg3 = -20; int Arg4 = 100; long long Arg5 = 322LL; verify_case(4, Arg5, collect(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 3; int Arr1[] = {1000000000, -1000000000, 1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 47; int Arg3 = 47; int Arg4 = 47; long long Arg5 = 3000000000LL; verify_case(5, Arg5, collect(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    CollectBoxes ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
