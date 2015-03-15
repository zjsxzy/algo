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

const int MAXN = 1000000 + 5;
int N, k;
int a[MAXN];
int search(int l, int r, int kth) {
	// cout << kth << " ";
	// for (int i = l; i <= r; i++) {
	// 	cout << a[i] << " ";
	// }
	// cout << endl;
	if (l == r) {
		return a[l];
	}
	int pivot = a[r], p = l;
	for (int i = l; i < r; i++) {
		if (a[i] <= pivot) swap(a[p++], a[i]);
	}
	swap(a[p], a[r]);
	int cnt = p - l + 1;
	if (kth == cnt) return a[p];
	else if (kth > cnt) return search(p + 1, r, kth - cnt);
	else return search(l, p - 1, kth);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d%d", &N, &k);
	for (int i = 0; i < N; i++) {
		scanf("%d", a + i);
	}
	if (k > N) {
		cout << -1 << endl;
		return 0;
	}
	int ret = search(0, N - 1, k);
	cout << ret << endl;
	return 0;
}

