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

const int MAXN = 500000 + 5;
struct Cell {
	int a, b, index;
	Cell() {}
	Cell(int a, int b, int index) : a(a), b(b), index(index) {}
	bool operator < (const Cell & pt) const {
		return a < pt.a;
	}
};
Cell cell[MAXN];
int n, k;
set<int> points, difference;
priority_queue<pair<int, int> > pq;
int diff[MAXN];

void add_point(int t) {
	points.insert(t);
	set<int>::iterator it = points.find(t);
	set<int>::iterator prev, nxt;
	it--; prev = it;
	it++; it++;
	nxt = it;

	if (--diff[*nxt - *prev] == 0) difference.erase(*nxt - *prev);
	if (++diff[t - *prev] == 1) difference.insert(t - *prev);
	if (++diff[*nxt - t] == 1) difference.insert(*nxt - t);
}

void del_point(int t) {
	set<int>::iterator it = points.find(t);
	set<int>::iterator prev, nxt;
	it--; prev = it;
	it++; it++;
	nxt = it;
	points.erase(points.find(t));

	if (--diff[t - *prev] == 0) difference.erase(t - *prev);
	if (--diff[*nxt - t] == 0) difference.erase(*nxt - t);
	if (++diff[*nxt - *prev] == 1) difference.insert(*nxt - *prev);
}

int max_difference() {
	set<int>::iterator it = difference.end();
	return *(--it);
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		cell[i] = Cell(a, b, i);
	}
	
	memset(diff, 0, sizeof(diff));

	points.insert(0); points.insert(n + 1);
	++diff[n + 1]; difference.insert(n + 1);

	sort(cell + 1, cell + n + 1);
	int ret = 2000000000;
	for (int i = 1, j = 1; i <= 32000; i++) {
		for (; j <= n && cell[j].a == i; j++) {
			add_point(cell[j].index);
			pq.push(MP(cell[j].b, cell[j].index));
		}
		while (max_difference() <= k && pq.size() != 0) {
			del_point(pq.top().second);
			if (max_difference() <= k) {
				pq.pop();
			} else {
				add_point(pq.top().second);
				break;
			}
		}
		if (max_difference() <= k) {
			ret = min(ret, pq.top().first * i);
		}
	}
	printf("%d\n", ret);
	return 0;
}

