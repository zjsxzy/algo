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

const int MAXN = 1000 + 5;
int n;
LL L[MAXN];
LL A, B, C;
char str[MAXN];

int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%lld", L + i);
		scanf("%lld%lld%lld", &A, &B, &C);
		A %= C; B %= C;
		scanf("%s", str);
		for (int i = 0; i < n; i++) {
			if (str[i] == 'R') {
				for (int j = 0; j < (n - i) / 2; j++)
					swap(L[i + j], L[n - 1 - j]);
			} else if (str[i] == 'A') {
				for (int j = i; j < n; j++) {
					L[j] += A;
					L[j] %= C;
				}
			} else {
				for (int j = i; j < n; j++) {
					L[j] *= B;
					L[j] %= C;
				}
			}
			printf("%lld%c", L[i], i == n - 1 ? '\n' : ' ');
		}
	}
	return 0;
}

