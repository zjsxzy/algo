#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> t(n), l(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> l[i];
    }
    for (int k = 1; k <= d; k++) {
        vector<int> w;
        for (int i = 0; i < n; i++) {
            w.push_back(t[i] * (l[i] + k));
        }
        sort(w.rbegin(), w.rend());
        cout << w[0] << '\n';
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