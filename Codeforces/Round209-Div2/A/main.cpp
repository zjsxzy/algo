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

int mat[55][55];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
	int res = 2500;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (mat[i][j]) {
				if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
					res = min(res, 2);
				else res = min(res, 4);
			}
		}
	cout << res << endl;
	return 0;
}
