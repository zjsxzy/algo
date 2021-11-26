#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
	int n;
	LL l, r, k;
	cin >> n >> l >> r >> k;
	vector<int> a(n);
	for (auto& x: a) {
		cin >> x;
	}
	sort(a.begin(), a.end());
	LL sum = 0, res = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= l && a[i] <= r && sum + a[i] <= k) {
			res++;
			sum += a[i];
		}
	}
	cout << res << endl;
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

