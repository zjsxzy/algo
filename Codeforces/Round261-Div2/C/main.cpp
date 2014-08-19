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

const int MAXN = 1000 + 5;
int n, k, d, arr[MAXN][MAXN];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	cin >> n >> k >> d;
	for (int i = 0; i < n; i++) {
		int l = 0;
		bool flag = false;
		for (int j = i; j; j /= k) {
			arr[i][++l] = j % k;
			if (l > d) {
				flag = true;
				break;
			}
		}
		if (flag) {
			puts("-1");
			return 0;
		}
	}
	for (int i = d; i; i--)
		for (int j = 0; j < n; j++)
			printf("%d%c", arr[j][i] + 1, j == n - 1 ? '\n' : ' ');
	return 0;
}

