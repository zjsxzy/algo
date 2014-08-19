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
int n, k, p;
int ans[maxn];
LL res;

int main() {
	cin >> n >> k >> p;
	for (int i = 1; i <= n - k; i++)
		ans[i] = 1;
	for (int i = n - k + 1; i <= n; i++) {
		if ((LL)p * (i - 1) % 100 == 0) {
			LL j = (LL)p * (i - 1) / 100;
			ans[i] = ans[j] + 1;
		} else {
			LL j = (LL)p * (i - 1) / 100 + 1;
			ans[i] = ans[j] + 1;
		}
	}
	res = 0;
	for (int i = 1; i <= n; i++)
		res += ans[i];
	cout << res << endl;
	for (int i = 1; i <= n; i++) {
		cout << ans[i];
		if (i == n) cout << endl;
		else cout << " ";
	}
	return 0;
}
