#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
	int x, y;
	cin >> x >> y;
	if (x % 2 == 0) {
		if (x > 0 || (x == 0 && y % 2 == 0)) cout << "YES" << endl;
		else cout << "NO" << endl;
	} else {
		cout << "NO" << endl;
	}
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

