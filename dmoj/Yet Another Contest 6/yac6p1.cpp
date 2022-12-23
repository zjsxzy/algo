#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    for (int curr = 1; curr <= n; curr++) {
        for (int i = curr + 1; i <= n; i++) {
            cout << curr << ' ' << i << endl;
            m--;
            if (m == 0) return;
        }
    }
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}