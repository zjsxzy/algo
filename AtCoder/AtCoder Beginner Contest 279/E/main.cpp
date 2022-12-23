#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m + 1), b(n + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        b[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        swap(b[a[i]], b[a[i] + 1]);
    }
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        pos[b[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        b[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        if (b[a[i]] == 1) {
            cout << pos[b[a[i] + 1]] << endl;
        } else if (b[a[i] + 1] == 1) {
            cout << pos[b[a[i]]] << endl;
        } else {
            cout << pos[1] << endl;
        }
        swap(b[a[i]], b[a[i] + 1]);
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