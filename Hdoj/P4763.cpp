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

const int maxn = 1000005;
int nxt[maxn];
void ExtendedKMP(char a[], int M) {
	int i, j, k;
	for (j = 0; 1 + j < M && a[j] == a[1 + j]; j++);
	nxt[1] = j;
	k = 1;
	for (i = 2; i < M; i++) {
		int len = k + nxt[k], L = nxt[i - k];
		if (L < len - i) {
			nxt[i] = L;
		} else {
			for (j = max(0, len - i); i + j < M && a[j] == a[i + j]; j++);
			nxt[i] = j;
			k = i;
		}
	}
}
char theme[maxn];

int main() {
	int Test;
	scanf("%d", &Test);
	while (Test--) {
		memset(nxt, 0, sizeof(nxt));
		scanf("%s", theme);
		int n = strlen(theme);
		ExtendedKMP(theme, n);

		int res = 0, mx = 0;
		int len = n / 3;
		int l = len, r = n - 2 * len;
		for (int i = l; i <= r; i++)
			mx = max(mx, nxt[i]);
		for (int i = n - len; i < n; i++) {
			if (nxt[i] == n - i) {
				if (mx >= nxt[i]) {
					res = max(res, nxt[i]);
				}
			}
			mx = max(mx, nxt[--l]);
			mx = max(mx, nxt[++r]);
			mx = max(mx, nxt[++r]);
		}
		printf("%d\n", res);
	}
	return 0;
}
