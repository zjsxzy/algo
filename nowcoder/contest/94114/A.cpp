#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (auto& x: h) cin >> x;
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j){
        return h[i] > h[j];
    });
    LL res = 0, p;
    for (int i = 0; i < n; i++) {
        LL t = (LL)(i + 1) * (i + 1) * h[ord[i]];
        if (t > res) {
            res = t;
            p = i;
        }
    }
    cout << p + 1 << endl;
    vector<int> ans;
    for (int i = 0; i <= p; i++) ans.push_back(ord[i] + 1);
    sort(ans.begin(), ans.end());
    for (auto x: ans) cout << x << ' ';
    cout << endl;
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