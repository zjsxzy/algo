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

const int MAXN = 45;
int dp[MAXN][MAXN][MAXN][MAXN];
int t[MAXN][MAXN];
void hanoi(int n, int a, int b, int c) {

int main() {
	int n;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> t[i][j];
	cin >> n;
	hanoi(n, n, 0, 0);
}

