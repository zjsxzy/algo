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
int nxt[maxn << 1];
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
	nxt[0] = i; 
}

char num[maxn];
int main() {
	int Test;
	scanf("%d", &Test);
	for (int cas = 1; cas <= Test; cas++) {
		printf("Case %d: ", cas);
		scanf("%s", num);
		int n = strlen(num);
		for (int i = 0; i < n; i++) {
			num[i + n] = num[i];
		}
		int less = 0, greater = 0, equal = 0;
		int cycle = n;
		ExtendedKMP(num, n << 1);
		for (int i = 1; i < n; i++) {
			if (i + nxt[i] >= n) {
				cycle = n % i ? n : i;
				break;
			}
		}
		for (int i = 0; i < cycle; i++) {
			if (nxt[i] >= n) {
				equal++;
			}
			char a = num[nxt[i]], b = num[i + nxt[i]];
			if (a < b) greater++;
			else if (a > b) less++;
		}
		printf("%d %d %d\n", less, equal, greater);
	}
	return 0;
}
