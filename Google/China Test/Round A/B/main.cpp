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
#include <limits.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

vector<pair<int, int> > ans;
int main() {
	queue<pair<int, int> > q;
	map<pair<int, int>, int> d;
	q.push(MP(1, 1));
	d[MP(1, 1)] = 0;
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		ans.PB(cur);
		if (d[cur] == 64) continue;
		q.push(MP(cur.first, cur.first + cur.second));
		q.push(MP(cur.first + cur.second, cur.second));
		d[MP(cur.first, cur.first + cur.second)] = d[cur] + 1;
		d[MP(cur.first + cur.second, cur.second)] = d[cur] + 1;
	}
	int Test;
	scanf("%d", &Test);
	for (int cas = 1; cas <= Test; cas++) {
		printf("Case #%d:", cas);
		int type;
		scanf("%d", &type);
		if (type == 1) {
			int n;
			scanf("%d", &n);
			n--;
			printf(" %d %d\n", ans[n].first, ans[n].second);
		} else {
			int p, q;
			scanf("%d%d", &p, &q);
			for (int i = 0; i < ans.size(); i++) {
				if (ans[i] == MP(p, q)) {
					printf(" %d\n", i + 1);
					break;
				}
			}
		}
	}
	return 0;
}
