#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) flag = false;
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
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