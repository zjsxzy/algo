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

bool intersect(int l, int r, int ll, int rr) {
	if (l > r) swap(l, r);
	if (ll > rr) swap(ll, rr);
	return (l < ll && ll < r && r < rr) || (r > rr && rr > l && l > ll);
}

int main() {
	int n;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];
	for (int i = 1; i < n; i++) {
		int l = x[i - 1], r = x[i];
		for (int j = 1; j < i; j++) {
			int ll = x[j - 1], rr = x[j];
			if (intersect(l, r, ll, rr)) {
//				cout << l << " " << r << " " << ll << " " << rr << endl;
				puts("yes");
				return 0;
			}
		}
	}
	puts("no");
	return 0;
}
