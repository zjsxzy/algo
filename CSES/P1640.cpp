#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    unordered_map<int, vector<int>> pos;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        if (x - a[i] != a[i]) {
            if (pos.find(x - a[i]) != pos.end()) {
                cout << i + 1 << ' ' << pos[x - a[i]][0] + 1 << endl;
                return;
            }
        } else {
            if (pos.find(a[i]) != pos.end() && pos[a[i]].size() > 1) {
                cout << pos[a[i]][0] + 1 << ' ' << pos[a[i]][1] + 1 << endl;
            }
        }
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