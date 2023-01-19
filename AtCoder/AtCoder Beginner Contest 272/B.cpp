#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        vector<int> attend(t);
        for (int j = 0; j < t; j++) {
            int x;
            cin >> x;
            x--;
            attend[j] = x;
        }
        for (int j = 0; j < t; j++) {
            for (int k = j + 1; k < t; k++) {
                g[attend[j]][attend[k]] = g[attend[k]][attend[j]] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!g[i][j]) {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}