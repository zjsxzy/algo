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

const int maxn = 10000 + 5;
int n;
struct data {
	int val, idx, ori;
	bool operator < (const data &pt) const {
		return val < pt.val;
	}
};
bool cmp(const data &a, const data &b) {
	return a.ori < b.ori;
}
data p[maxn];
bool mk[maxn];
int pos[maxn];

int run(const int *a, int n) {
	for (int i = 1; i <= n; i++) {
		p[i].val = a[i - 1];
		p[i].ori = i;
	}
	sort(p + 1, p + n + 1);
	for (int i = 1; i <= n; i++)
		p[i].idx = i;
	sort(p + 1, p + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		pos[i] = p[i].idx;
	}
	LL cnt = 0;
	memset(mk, 0, sizeof(mk));
	for (int i = 1; i <= n; i++) {
		if (!mk[i]) {
			mk[i] = true;
			cnt++;
			for (int j = pos[i]; j != i; j = pos[j]) {
				mk[j] = true;
			}
		}
	}
	return n - cnt;
}

int main() {
	int a[] = {2, 3, 1};
	cout << run(a, 3) << endl;
	return 0;
}
