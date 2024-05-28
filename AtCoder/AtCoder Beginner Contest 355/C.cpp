#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, t;
    cin >> n >> t;
    vector<int> row(n + 1, n), col(n + 1, n), diag(2, n);
    for (int k = 1; k <= t; k++) {
        int x;
        cin >> x;
        int i = (x - 1) / n + 1, j = (x - 1) % n + 1;
        row[i]--;
        if (row[i] == 0) {
            cout << k << endl;
            return;
        }
        col[j]--;
        if (col[j] == 0) {
            cout << k << endl;
            return;
        }
        if (i == j) {
            diag[0]--;
            if (diag[0] == 0) {
                cout << k << endl;
                return;
            }
        }
        if (i + j == n + 1) {
            diag[1]--;
            if (diag[1] == 0) {
                cout << k << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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