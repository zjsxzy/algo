#line 2 "EllysKeys.cpp"
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 55;
int dgr[maxn];    //每个点的度
bool cmp(const int &a, const int &b) {
    return dgr[a] < dgr[b];
}
struct MaxClique {
    bool E[maxn][maxn];
    int n;                    //图的所在，需传入
    int c[maxn],stack[maxn],ans,ansStack[maxn];//后俩:答案和可行点
    void init(int n) {
        this->n = n;
        memset(E, 0, sizeof(E));
    }
///    arr中保存了len个点, 程序要筛选出和a相连的点,并保存在newArr
    void intersect(int a,int*arr,int len,int*newArr,int&newLen){
        newLen = 0;
        for(int i = 0; i < len; i ++)
            if(E[a][ arr[i] ])    newArr[newLen ++] = arr[i];
    }
    bool dfs(int *arr, int len, int size) {
        if(len == 0) {
            if(size > ans) {
                ans = size;
                copy(stack, stack+ans, ansStack);
                return true;
            }
            return false;
        }
        int newArr[maxn], newLen, a, b;
        while(len != 0 && size + len > ans) {               //剪枝
            a = arr[0];
            stack[size] = a; //断言a在最大clique里, 装入堆栈
            if(size + c[a] <= ans)                return false;//剪枝
            arr ++;    len --;
            intersect(a, arr, len, newArr, newLen);
            if(dfs(newArr, newLen, size+1))    return true;//剪枝
        }
        return false;
    }
    int solve() {
        memset(dgr, 0, sizeof(dgr));
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                if(E[i][j])    dgr[j] ++;
        int arr[maxn], newArr[maxn], newLen;
        for(int i = 0; i < n; i ++)    arr[i] = i;
        sort(arr, arr+n, cmp);                                   //剪枝
        ans = 0;
        for(int i = n-1; i >= 0; i --) {
            intersect(arr[i], arr+i, n-i, newArr, newLen);
            stack[0] = arr[i];//断言arr[i]在最大clique里, 装入堆栈
            dfs(newArr, newLen, 1);
            c[arr[i]] = ans;
        }
        return ans;
    }
}g;

class EllysKeys {
	public:
	int getMax(vector <string> keys) {
        int n = keys.size();
        if (n == 0) return 0;
        int m = keys[0].size();
        g.init(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                bool flag = true;
                for (int k = 0; k < m; k++) {
                    if (keys[i][k] == '^' && keys[j][k] == '^') {
                        flag = false;
                        break;
                    }
                }
                g.E[i][j] = g.E[j][i] = flag;
            }
        }
        int res = g.solve();
        return res;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"..^.^^.^",
 "^.^^...^",
 "^.....^."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, getMax(Arg0)); }
	void test_case_1() { string Arr0[] = {"^.^"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getMax(Arg0)); }
	void test_case_2() { string Arr0[] = {"^..^...^",
 ".^^.....",
 ".^..^...",
 "..^...^.",
 "...^^.^."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, getMax(Arg0)); }
	void test_case_3() { string Arr0[] = {"....................",
 "^^^^^^..^^^^..^^^^^.",
 "..^^...^^..^^.^^..^^",
 "..^^...^^..^^.^^^^^.",
 "..^^...^^..^^.^^....",
 "..^^....^^^^..^^....",
 "....................",
 ".^^^^...^^^^..^^^^..",
 "^^...^.^^..^^.^^..^^",
 "^^.....^^..^^.^^..^^",
 "^^...^.^^..^^.^^..^^",
 ".^^^^...^^^^..^^^^..",
 "....................",
 "...^^^^^^...^^^^^...",
 "...^^.......^^..^^..",
 "...^^^^^....^^^^^...",
 "...^^.......^^.^^...",
 "...^^^^^^...^^..^^..",
 "...................."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, getMax(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	EllysKeys ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
