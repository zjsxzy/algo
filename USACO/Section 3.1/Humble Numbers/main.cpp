/*
ID: frankzh1
TASK: humble
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
	int k, n;
	cin >> k >> n;
	vector<int> nums(k);
	for (auto &x: nums) {
		cin >> x;
	}
	sort(nums.begin(), nums.end());

	set<pair<LL, int>> st;
	st.insert({nums[0], 0});
	for (int i = 1; i < n; i++) {
		auto it = st.begin();
		LL val = it->first;
		int idx = it->second;
		//cout << i << " " << val << " " << idx << endl;
		st.insert({val * nums[idx], idx});
		if (idx + 1 < k) st.insert({val / nums[idx] * nums[idx + 1], idx + 1});
		st.erase(it);
	}
	auto res = st.begin();
	cout << res->first << endl;
}

int main() {
    freopen("humble.in", "r", stdin);
	freopen("humble.out", "w", stdout);
    solve();
    return 0;
}

