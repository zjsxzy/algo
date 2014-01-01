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

const int MAXN = 300000 + 5;
struct node {
	int rate;
	int id, res;
	bool operator < (const node &pt) const {
		return rate == pt.rate ? id < pt.id : rate < pt.rate;
	}
}p[MAXN];
int n;

bool cmp(const node &A, const node &B) {
	return A.id < B.id;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].rate;
		p[i].id = i;
	}
	sort(p, p + n);
	int cur = p[0].rate;
	p[0].res = cur;
	cur++;
	for (int i = 1; i < n; i++) {
		int temp = max(cur, p[i].rate);
		p[i].res = temp;
		cur = temp + 1;
	}
	sort(p, p + n, cmp);
	for (int i = 0; i < n; i++)
		printf("%d%c", p[i].res, i == n - 1 ? '\n' : ' ');
	return 0;
}

