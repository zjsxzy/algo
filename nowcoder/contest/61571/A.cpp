#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n < 3 * k) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < k; i++) {
        cout << "you";
    }
    for (int i = 3 * k; i < n; i++) {
        cout << 'y';
    }
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