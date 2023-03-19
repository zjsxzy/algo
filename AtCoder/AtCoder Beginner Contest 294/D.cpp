#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, q;
    cin >> n >> q;
    set<int> ncall, called;
    for (int i = 1; i <= n; i++) ncall.insert(i);
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x = *ncall.begin();
            called.insert(x);
            ncall.erase(x);
        } else if (t == 2) {
            int x;
            cin >> x;
            called.erase(x);
        } else {
            int x = *called.begin();
            cout << x << endl;
        }
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