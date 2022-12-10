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

int k, x, n, m;
bool exist;

string MakeString(int len, int ac, bool b, bool e) {
	string ret = "";
	ret.resize(len);
	int l = 0, r = len;
	if (b) ret[l++] = 'C';
	if (e) ret[--r] = 'A';
	while (ac--) {
		ret[l++] = 'A'; ret[l++] = 'C';
	}
	while (l < r) {
		ret[l++] = 'Z';
	}
	return ret;
}

LL Count(int k, LL ac1, LL ac2, bool b1, bool e1, bool b2, bool e2) {
	if (k == 2) return ac2;
	return Count(k - 1, ac2, ac1 + ac2 + (e1 * b2), b2, e2, b1, e2);
}

void Check(LL ac1, LL ac2, bool b1, bool e1, bool b2, bool e2) {
	if (2 * ac1 + b1 + e1 > n) return;
	if (2 * ac2 + b2 + e2 > m) return;
	if (Count(k, ac1, ac2, b1, e1, b2, e2) == x) {
		exist = true;
		cout << MakeString(n, ac1, b1, e1) << "\n" << MakeString(m, ac2, b2, e2) << endl;
		return;
	}
}

int main() {
	cin >> k >> x >> n >> m;
	exist = false;
	for (int i = 0; i + i <= n && !exist; i++) {
		for (int j = 0; j + j <= m && !exist; j++) {
			for (int st = 0; st < 16 && !exist; st++) {
				Check(i, j, st & 1, (st >> 1) & 1, (st >> 2) & 1, (st >> 3) & 1);
			}
		}
	}
	if (!exist) puts("Happy new year!");
	return 0;
}

