#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    int agree = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "For") agree++;
    }
    if (agree > n / 2) cout << "Yes" << endl;
    else cout << "No" << endl;
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