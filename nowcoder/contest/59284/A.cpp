#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int x;
    cin >> x;
    if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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