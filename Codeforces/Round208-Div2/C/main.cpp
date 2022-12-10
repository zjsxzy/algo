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

const int maxn = 100000 + 5;
char push[4][10] = {"pushStack", "pushQueue", "pushFront", "pushBack"};
char pop[4][10] = {"popStack", "popQueue", "popFront", "popBack"};
int a[maxn];
bool mk[maxn];

bool cmpA(int i, int j) {
	return a[i] > a[j];
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	memset(mk, 0, sizeof(mk));
	for (int i = 0; i < n; i++) {
		int j = i;
		for (; j < n && a[j] != 0; j++);
		vector<int> pos;
		for (int k = i; k < j; k++) {
			pos.PB(k);
		}
		sort(pos.begin(), pos.end(), cmpA);
		for (int k = 0; k < min(3, SZ(pos)); k++) {
			mk[pos[k]] = true;
		}
		int cnt = 0;
		for (int k = i; k < j; k++) {
			if (mk[k]) {
				if (cnt == 0) {
					printf("%s\n", push[2]);
				} else if (cnt == 1) {
					printf("%s\n", push[1]);
				} else if (cnt == 2) {
					printf("%s\n", push[0]);
				}
				cnt++;
			} else {
				if (cnt < 3) {
					printf("%s\n", push[0]);
				} else {
					printf("%s\n", push[1]);
				}
			}
		}
		if (j != n) {
			printf("%d", cnt);
			if (cnt >= 1) {
				printf(" %s", pop[2]);
			}
			if (cnt >= 2) {
				printf(" %s", pop[1]);
			}
			if (cnt >= 3) {
				printf(" %s", pop[0]);
			}
			puts("");
		}
		i = j;
	}
	return 0;
}
