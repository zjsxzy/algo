#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    if (n >= 2000) {
        cout << "YES" << endl;
        return;
    }
    vector<int> cnt(4000005);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cnt[a[i] + a[j]]++;
        }
    }
    for (int i = 1; i <= 4000000; i++) {
        if (cnt[i] > 1) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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