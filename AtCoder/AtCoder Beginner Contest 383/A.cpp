#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    int curr = 0, prev = 0;
    for (int i = 0; i < n; i++) {
        int t, v;
        cin >> t >> v;
        if (prev != 0) {
            curr = max(0, curr - (t - prev));
        }
        prev = t;
        curr += v;
        // cout << t << ' ' << v << ' ' << curr << endl;
    }
    cout << curr << endl;
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