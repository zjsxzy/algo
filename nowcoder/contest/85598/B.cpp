#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int even = 0, odd = 0;
    for (auto& x: a) {
        cin >> x;
        if (x & 1) odd++;
        else even++;
    }
    if (even >= odd) cout << even - odd << endl;
    else {
        odd -= even;
        if (odd & 1) cout << 1 << endl;
        else cout << 0 << endl;
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