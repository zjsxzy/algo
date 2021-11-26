#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	return a.second < b.second;
}

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[i].first = x;
		a[i].second = i;
	}
	sort(a.rbegin(), a.rend());
	vector<int> x(n);
	int dis = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			dis++;
			x[a[i].second] = dis;
		} else {
			x[a[i].second] = -dis;
		}
	}
	sort(a.begin(), a.end(), cmp);
	LL sum = 0;
	for (int i = 0; i < n; i++) {
		sum += 2LL * a[i].first * abs(x[i]);
	}
	cout << sum << endl;
	cout << 0;
	for (int i = 0; i < n; i++) {
		cout << " " << x[i];
	}
	cout << endl;
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

