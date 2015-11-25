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

const int MAXN = 20 + 5;
int n;
struct pyramid{
	pair<int, int> pos;
	int l, r, w;
	bool operator < (const pyramid &pt) const {
		return l == pt.l ? r < pt.r : l < pt.l;
	}
};
pyramid p[MAXN];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int ts;
	scanf("%d", &ts);
	for (int cas = 1; cas <= ts; cas++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", &p[i].pos.first, &p[i].pos.second, &p[i].w);
			p[i].l = p[i].pos.first - p[i].pos.second;
			p[i].r = p[i].pos.first + p[i].pos.second;
		}
		double res = 0.0;
		for (int st = 1; st < (1 << n); st++) {
			vector<pyramid> vec;
			double rev = 0.0;
			for (int j = 0; j < n; j++) {
				if (st & (1 << j)) {
					vec.PB(p[j]);
					rev += p[j].w;
				}
			}
			sort(vec.begin(), vec.end());
			int rr = vec[0].r;
			double sum = vec[0].pos.second * vec[0].pos.second;
			for (int i = 1; i < vec.size(); i++) {
				if (vec[i].r <= rr) continue;
				else if (vec[i].l < rr) {
					sum += vec[i].pos.second * vec[i].pos.second - (double)(vec[i].r - rr) * (vec[i].r - rr) / 4;
					rr = vec[i].r;
				} else if (vec[i].l >= rr) {
					sum += vec[i].pos.second * vec[i].pos.second;
					rr = vec[i].r;
				}
			}
			res = max(res, rev - sum);
		}
		printf("Case #%d: %.2f\n", cas, res);
	}
	return 0;
}

