#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> ans(n, -1);
	vector<pair<pair<int, char>, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first.first;
		a[i].second = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i].first.second;
	}
	sort(a.begin(), a.end());
	vector<vector<pair<int, int>>> stk(2);

	for (auto [xd, i] : a) {
		auto [x, d] = xd;
		if (d == 'R') {
			stk[x % 2].push_back({x, i});
		} else {
			if (!stk[x % 2].empty()) {
				auto [y, j] = stk[x % 2].back();
				stk[x % 2].pop_back();
				ans[i] = ans[j] = abs(x - y) / 2;
			} else {
				stk[x % 2].push_back({-x, i});
			}
		}
	}
	for (int k = 0; k < 2; k++) {
		while (stk[k].size() >= 2) {
			auto [x, i] = stk[k].back();
			stk[k].pop_back();
			auto [y, j] = stk[k].back();
			stk[k].pop_back();
			ans[i] = ans[j] = (m - x) + (x - y) / 2;
		}
	}
	for (auto &x : ans) {
		cout << x << " ";
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

