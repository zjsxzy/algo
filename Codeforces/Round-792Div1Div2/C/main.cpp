#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int x = 0;
    while (x < n && is_sorted(a[x].begin(), a[x].end())) {
        x++;
    }
    if (x == n) {
        cout << "1 1" << '\n';
        return;
    }

    auto b = a[x];
    sort(b.begin(), b.end());
    vector<int> pos;
    for (int i = 0; i < m; i++) {
        if (b[i] != a[x][i]) {
            pos.push_back(i);
        }
    }
    if (pos.size() > 2) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        swap(a[i][pos[0]], a[i][pos[1]]);
        if (!is_sorted(a[i].begin(), a[i].end())) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << pos[0] + 1 << ' ' << pos[1] + 1 << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

