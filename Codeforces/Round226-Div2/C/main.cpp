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

const int MAXN = 10000000 + 5;
int n, m;
int cnt[MAXN], mk[MAXN], sum[MAXN];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	sum[0] = sum[1] = 0;
	for (int x = 2; x <= MAXN - 5; x++) {
		int tot = 0;
		if (!mk[x]) {
			tot += cnt[x];
			for (int j = x + x; j <= MAXN; j += x) {
				mk[j] = true;
				tot += cnt[j];
			}
		}
		sum[x] = sum[x - 1] + tot;
	}
	int m;
	cin >> m;
	while (m--) {
		int l, r;
		cin >> l >> r;
		l = min(l, MAXN - 5);
		r = min(r, MAXN - 5);
		cout << sum[r] - sum[l - 1] << endl;
	}
	return 0;
}

