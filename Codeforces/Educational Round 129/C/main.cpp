#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& x: a) cin >> x;
    for (auto& x: b) cin >> x;
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
                swap(b[i], b[j]);
                ans.emplace_back(i + 1, j + 1);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (b[i] > b[j]) {
                swap(a[i], a[j]);
                swap(b[i], b[j]);
                ans.emplace_back(i + 1, j + 1);
            }
        }
    }
    if (is_sorted(a.begin(), a.end()) && is_sorted(b.begin(), b.end())) {
        cout << ans.size() << '\n';
        for (auto x: ans) {
            cout << x.first << " " << x.second << '\n';
        }
    } else {
        cout << -1 << '\n';
    }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

