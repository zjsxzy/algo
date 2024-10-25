#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int res = 1e9;
    for (auto [k, v]: cnt) {
        if (v >= 3) {
            res = min(res, k * 3);
        }
    }
    if (res == 1e9) cout << "no" << endl;
    else {
        cout << "yes" << endl;
        cout << res << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}