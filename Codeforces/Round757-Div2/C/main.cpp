#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const LL mod = 1e9 + 7;
void solve() {
	int n, m;
	cin >> n >> m;
	LL res = 0;
	for (int i = 0; i < m; i++) {
		int l, r, x;
		cin >> l >> r >> x;
		res |= x;
	}
	for (int i = 0; i < n - 1; i++) {
		res = (res * 2) % mod;
	}
	cout << res % mod << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	int ts;
	cin >> ts;
	while (ts--) {
		solve();
	}
    return 0;
}

