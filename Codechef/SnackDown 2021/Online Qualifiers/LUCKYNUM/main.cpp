#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
	bool flag = false;
	for (int i = 0; i < 3; i++) {
		int x;
		cin >> x;
		if (x == 7) flag = true;
	}
	if (flag) cout << "YES" << endl;
	else cout << "NO" << endl;
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

