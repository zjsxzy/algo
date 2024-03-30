#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL n, a, b;
    cin >> n >> a >> b;
    vector<LL> d(n), v;
    for (auto& x: d) {
        cin >> x;
        v.push_back(x % (a + b));
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    int m = v.size();
    for (int i = 0; i < m; i++) {
        v.push_back(v[i] + (a + b));
    }
    for (int i = 0; i < m; i++) {
        if (v[i + m - 1] - v[i] < a) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
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