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

const int maxn = 100005;
int nxt[maxn << 1];
int find_substring(char pattern[], int n) {
	vector<int> next(n + 1, 0);
	for (int i = 1; i < n; i++) {
		int j = i;
		while (j > 0) {
			j = next[j];
			if (pattern[j] == pattern[i]) {
				next[i + 1] = j + 1;
				break;
			}
		}
	}
	return n - next[n];
}

char str[maxn];
int main() {
	int Test;
	scanf("%d", &Test);
	while (Test--) {
		scanf("%s", str);
		int n = strlen(str);
		int cycle = find_substring(str, n);

		int res;
		if (cycle == n) res = n;
		else if (n % cycle) res = cycle - n % cycle;
		else res = 0;
		printf("%d\n", res);
	}
	return 0;
}
