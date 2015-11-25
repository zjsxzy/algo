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

const int MAXN = 100 + 5;
int n, m, q;
int sex[MAXN];
int mat[MAXN][MAXN];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int ts;
	cin >> ts;
	for (int cas = 1; cas <= ts; cas++) {
		printf("Case #%d:\n", cas);
		cin >> n >> m >> q;
		for (int i = 1; i <= n; i++) {
			cin >> sex[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				mat[i][j] = -1;
			}
		}
		for (int i = 0; i < m; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			mat[x][y] = mat[y][x] = z;
		}
		while (q--) {
			int op;
			cin >> op;
			if (op == 3) {
				int res = 0;
				for (int i = 1; i <= n; i++) {
					for (int j = i + 1; j <= n; j++) {
						if (sex[i] != sex[j] && mat[i][j] != -1) {
							// cout << i << " " << j << " " << mat[i][j] << endl;
							res += mat[i][j];
						}
					}
				}
				cout << res << endl;
			} else if (op == 1) {
				int x;
				cin >> x;
				sex[x] = 1 - sex[x];
			} else {
				int x, y, z;
				cin >> x >> y >> z;
				mat[x][y] = mat[y][x] = z;
			}
		}
	}
	return 0;
}

