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

const int maxn = 100000 + 50, maxm = 100000 + 50;
const LL INF = 1LL << 60;
int n, m, k;
int wgt[maxn];
LL sum[maxn], tm[maxm];

int main() {
	while (~scanf("%d %d %d", &n, &m, &k)) {
		sum[0] = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", wgt + i);
			sum[i] = sum[i - 1] + wgt[i];
		}
		tm[0] = 0;
		for (int i = 1; i <= m; i++) {
			int tmp;	scanf("%d", &tmp);
			tm[i] = tmp;
		}
		tm[m + 1] = INF;

		sort(tm + 1, tm + 1 + m);
		LL result = 0;
		LL cur = 0;
		for (int i = 1; i <= m + 1; i++) {
			if (cur + tm[i] - tm[i - 1] - 1 >= n) {
				result = tm[i - 1] + n - cur;
				break;
			}
			cur = cur + tm[i] - tm[i - 1] - 1; 
			LL shel = sum[cur] - k;
			LL ll = 1, rr = cur, mid;
			while (ll < rr) {
				mid = (ll + rr) >> 1;
				if (sum[mid] >= shel) rr = mid;
				else ll = mid + 1;
			}
			cur = ll - 1;
		}

		cout << result << endl;
	}
}
