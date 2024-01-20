#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a += x;
        b += y;
    }
    if (a > b) cout << "Takahashi" << endl;
    else if (a < b) cout << "Aoki" << endl;
    else cout << "Draw" << endl;
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