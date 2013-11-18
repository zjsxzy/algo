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

const int maxn = 50000 + 5;
int n, a[maxn], ll[maxn], rr[maxn];

void test() {
	LL ret = 0;
	map<int, int> gmx, gmn;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int mx = 0, mn = 50001;
			for (int k = i; k <= j; k++) {
				mx = max(mx, a[k]); mn = min(mn, a[k]);
			}
			gmx[mx]++;
			gmn[mn]++;
			ret += mx - mn;
		}
	}
	map<int, int>::iterator it;
	FOREACH(it, gmx) cout << it->first << " " << it->second << endl;
	FOREACH(it, gmn) cout << it->first << " " << it->second << endl;
	cout << ret << endl;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	//test();
	//set<int> appear;
	//map<int, int> gmx, gmn;
	LL sumMax = 0, sumMin = 0;

	a[0] = 50001; a[n + 1] = 50001;
	for (int i = 1; i <= n; i++) {
		ll[i] = i;
		while (a[i] >= a[ll[i] - 1]) {
			ll[i] = ll[ll[i] - 1];
		}
	}
	for (int i = n; i >= 1; i--) {
		rr[i] = i;
		while (a[i] > a[rr[i] + 1]) {
			rr[i] = rr[rr[i] + 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		//cout << a[i] << " " << ll[i] << " " << rr[i] << endl;
		//gmx[a[i]] += (i - ll[i] + 1) * (rr[i] - i + 1);
		sumMax += (LL)a[i] * (i - ll[i] + 1) * (rr[i] - i + 1);
	}

	//appear.clear();
	a[0] = 0; a[n + 1] = 0;
	for (int i = 1; i <= n; i++) {
		ll[i] = i;
		while (a[i] <= a[ll[i] - 1]) {
			ll[i] = ll[ll[i] - 1];
		}
	}
	for (int i = n; i >= 1; i--) {
		rr[i] = i;
		while (a[i] < a[rr[i] + 1]) {
			rr[i] = rr[rr[i] + 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		//cout << a[i] << " " << ll[i] << " " << rr[i] << endl;
		//gmn[a[i]] += (i - ll[i] + 1) * (rr[i] - i + 1);
		sumMin += (LL)a[i] * (i - ll[i] + 1) * (rr[i] - i + 1);
	}

	/*
	map<int, int>::iterator it;
	FOREACH(it, gmx) cout << it->first << " " << it->second << endl;
	FOREACH(it, gmn) cout << it->first << " " << it->second << endl;
	*/

	cout << sumMax - sumMin << endl;
	return 0;
}
