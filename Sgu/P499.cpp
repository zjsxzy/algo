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

const int maxn = 1000000 + 5;
int mk[maxn];
int n;

int main() {
	scanf("%d", &n);
	int mx = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		mk[x]++;
		mx = max(mx, x);
	}
	int res = 1;
	for (int i = mx; i >= 2; i--) {
		int cnt = 0;
		for (int j = 1; i * j <= mx; j++) {
			cnt += mk[i * j];
			if (cnt >= 2) break;
		}
		if (cnt >= 2) {
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}
