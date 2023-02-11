#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int x;
            cin >> x;
            x--;
            a[i] |= (1 << x);
        }
    }
    int res = 0;
    for (int s = 1; s < (1 << m); s++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (s >> j & 1) {
                cnt |= a[j];
            }
        }
        if (cnt == (1 << n) - 1) res++;
    }
    cout << res << endl;
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