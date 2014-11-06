#line 2 "ShadowSculpture.cpp"
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <climits>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

const int MAXN = 15;
const int dx[6] = {1, -1, 0, 0, 0, 0};
const int dy[6] = {0, 0, 1, -1, 0, 0};
const int dz[6] = {0, 0, 0, 0, 1, -1};
bool has[MAXN][MAXN][MAXN], vst[MAXN][MAXN][MAXN];
struct cube {
	int x, y, z;
	cube() {}
	cube(int x, int y, int z) : x(x), y(y), z(z) {}
};
class ShadowSculpture {
    public:
		int n;
		
    string possible(vector <string> XY, vector <string> YZ, vector <string> ZX) {
		n = XY.size();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					has[i][j][k] = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (XY[i][j] == 'N') {
					for (int k = 0; k < n; k++)
						has[i][j][k] = false;
				}
				if (YZ[i][j] == 'N') {
					for (int k = 0; k < n; k++)
						has[k][i][j] = false;
				}
				if (ZX[i][j] == 'N') {
					for (int k = 0; k < n; k++)
						has[j][k][i] = false;
				}
			}
		}
		bool flag = false;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (XY[i][j] == 'Y' || YZ[i][j] == 'Y' || ZX[i][j] == 'Y')
					flag = true;
			}
		if (!flag) return "Possible";
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++) {
					if (!has[i][j][k]) continue;
					memset(vst, 0, sizeof(vst));
					cube start = cube(i, j, k);
					queue<cube> q;
					q.push(start);
					vst[i][j][k] = true;
					while (!q.empty()) {
						cube curr = q.front(); q.pop();
						for (int l = 0; l < 6; l++) {
							int x = curr.x + dx[l], y = curr.y + dy[l], z = curr.z + dz[l];
							if (check(x, y, z)) {
								vst[x][y][z] = true;
								q.push(cube(x, y, z));
							}
						}
					}
					
					bool ok = true;
					for (int u = 0; u < n; u++)
						for (int v = 0; v < n; v++) {
							if (XY[u][v] == 'Y') {
								bool OK = false;
								for (int w = 0; w < n; w++) {
									if (vst[u][v][w]) {
										OK = true;
										break;
									}
								}
								if (!OK) ok = false;
							}
							if (YZ[u][v] == 'Y') {
								bool OK = false;
								for (int w = 0; w < n; w++) {
									if (vst[w][u][v]) {
										OK = true;
										break;
									}
								}
								if (!OK) ok = false;
							}
							if (ZX[u][v] == 'Y') {
								bool OK = false;
								for (int w = 0; w < n; w++) {
									if (vst[v][w][u]) {
										OK = true;
										break;
									}
								}
								if (!OK) ok = false;
							}
						}
					if (ok) return "Possible";
				}
		return "Impossible";
    }
	
	bool check(int x, int y, int z) {
		return 0 <= x && x < n && 0 <= y && y < n && 0 <= z && z < n && !vst[x][y][z] && has[x][y][z];
	}
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"YN","NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YN","NN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YN","NN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(0, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"YN","NY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YN","NY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YN","NY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Impossible"; verify_case(1, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"YYY","YNY","YYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YYY","YNY","YYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YYY","YNY","YYY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(2, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"YYY","YNY","YYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYY","YNY","YYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YYY","YNY","YYN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Impossible"; verify_case(3, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"N"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"N"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(4, Arg3, possible(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    ShadowSculpture ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
