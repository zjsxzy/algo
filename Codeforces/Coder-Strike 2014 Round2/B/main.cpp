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

const int MAXN = 20005;
int n, m, k;
int ret[MAXN];
int cnt[11];
vector<int> mem[11];
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			if (x == 1) {
				mem[j].push_back(i);
			}
		}
	}
	memset(ret, 0, sizeof(ret));
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		ret[a]--;
		cnt[b]++;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < mem[i].size(); j++) {
			ret[mem[i][j]] += cnt[i];
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d%c", ret[i], i == n - 1 ? '\n' : ' ');
	}
	return 0;
}

