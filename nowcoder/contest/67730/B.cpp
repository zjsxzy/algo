#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    vector<pair<int, int>> vec;
    for (auto [k, v]: cnt) {
        vec.emplace_back(v, k);
    }
    sort(vec.begin(), vec.end());
    if (vec.back().first >= n - k) {
        cout << n - k << endl;
    } else {
        cout << vec.back().first << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}