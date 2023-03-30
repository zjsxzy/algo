#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> pos;
    for (int i = 0; i < n; i++) {
        if (pos.count(x - a[i])) {
            cout << pos[x - a[i]] << ' ' << i + 1 << endl;
            return;
        }
        pos[a[i]] = i + 1;
    }
    cout << "IMPOSSIBLE" << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}