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

int n;
int a[33][33], b[33][33];

void flip() {
	int temp[33][33];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			temp[j][n - i + 1] = a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = temp[i][j];
		}
	}
}

int main() {
	while (cin >> n && n) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> b[i][j];
			}
		}
		int ret = 0;
		for (int k = 0; k < 4; k++) {
			flip();
			int cnt = 0;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					cnt += a[i][j] == b[i][j];
			ret = max(ret, cnt);
		}
		cout << ret << endl;
	}
	return 0;
}

