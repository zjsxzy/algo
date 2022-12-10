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

const int MAXN = 105;
bool flagR[MAXN], flagC[MAXN];
int row[MAXN], col[MAXN];
int r, c, n, m;
int ret, cntR, cntC, tot;

void dfs(int id) {
	if (tot > ret) return;
	if (id == n) {
		if (tot >= n + m) {
			ret = min(ret, tot);
		} else {
			for (int i = 0; i <= r - cntR; i++) {
				for (int j = 0; j <= c - cntC; j++) {
					int temp = tot + i * (c - cntC) + j * (r - cntR);
					if (temp >= n + m) {
						ret = min(ret, temp);
						break;
					}
				}
			}
		}
	} else {
		int rx = row[id], cy = col[id];
		if (!flagR[rx]) {
			flagR[rx] = true;
			cntR++;
			tot += c - cntC;
			dfs(id + 1);
			tot -= c - cntC;
			cntR--;
			flagR[rx] = false;
		} else {
			dfs(id + 1);
		}

		if (!flagC[cy]) {
			flagC[cy] = true;
			cntC++;
			tot += r - cntR;
			dfs(id + 1);
			tot -= r - cntR;
			cntC--;
			flagC[cy] = false;
		} else {
			dfs(id + 1);
		}
	}
}

int main(int argc, char const *argv[])
{
	int Test;
	scanf("%d", &Test);
	while (Test--) {
		scanf("%d%d%d%d", &r, &c, &n, &m);
		for (int i = 0; i < n; i++) {
			int d;
			scanf("%d%d%d", &row[i], &col[i], &d);
		}
		tot = cntR = cntC = 0;
		ret = 10000;
		memset(flagR, 0, sizeof(flagR));
		memset(flagC, 0, sizeof(flagC));
		dfs(0);
		printf("%d\n", ret);
	}
	return 0;
}