#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n);
    for (auto& x: a) cin >> x;
    LL mx = a[n - 1], mn = LLONG_MAX;
    int mx_i = n - 1;
    pair<int, int> mn_i;
    vector<pair<int, pair<int, int>>> ans;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > a[i + 1]) {
            if (mn > a[i + 1]) {
                cout << -1 << endl;
                return;
            } else {
                a[i] = mn;
                ans.push_back({i, mn_i});
            }
        }
        if (a[i] - mx < mn) {
            mn = a[i] - mx;
            mn_i = {i, mx_i};
        }
        if (a[i] > mx) {
            mx = a[i];
            mx_i = i;
        }
    }
    cout << ans.size() << endl;
    for (auto p: ans) {
        cout << p.first + 1 << " " << p.second.first + 1 << " " << p.second.second + 1 << endl;
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

