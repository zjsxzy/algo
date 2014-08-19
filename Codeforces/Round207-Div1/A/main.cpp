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

const int maxn = 300005;
int ans[maxn];

int main() {
	int n, m;
	cin >> n >> m;
	set<int> st;
	for (int i = 1; i <= n; i++) {
		st.insert(i);
	}
	memset(ans, 0, sizeof(ans));
	while (m--) {
		int l, r, x;
		cin >> l >> r >> x;
		set<int>::iterator it = st.lower_bound(l);
		while (*it <= r && it != st.end()) {
			if (*it == x) {
				it++;
				continue;
			}
			ans[*it] = x;
			int temp = *it;
			it++;
			st.erase(temp);
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d%c", ans[i], i == n ? '\n' : ' ');
	}
	return 0;
}
