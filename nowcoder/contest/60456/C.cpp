#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int m = 500;
int g[m + 5][10];

void solve() {
    int n;
    cin >> n;
    memset(g, 0, sizeof(g));
    for (int j = 1; j <= 8; j++) g[0][j] = 1;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if (a == 0) {
            for (int j = m; j >= 0; j--) {
                if (g[j][b] || g[j][b + 1]) {
                    g[j + 1][b] = g[j + 2][b] = g[j + 3][b] = 1;
                    g[j + 1][b + 1] = 1;
                    // cout << j << ' ' << b << endl;
                    break;
                }
            }
        } else if (a == 90) {
            for (int j = m; j >= 0; j--) {
                if (g[j][b] || g[j + 1][b + 1] || g[j + 1][b + 2]) {
                    g[j + 1][b] = g[j + 2][b] = 1;
                    g[j + 2][b + 1] = 1;
                    g[j + 2][b + 2] = 1;
                    // cout << j << ' ' << b << endl;
                    break;
                }
            }
        } else if (a == 180) {
            for (int j = m; j >= 0; j--) {
                if (g[j + 2][b] || g[j][b + 1]) {
                    g[j + 3][b] = 1;
                    g[j + 1][b + 1] = g[j + 2][b + 1] = g[j + 3][b + 1] = 1;
                    // cout << j << ' ' << b << endl;
                    break;
                }
            }
        } else if (a == 270) {
            for (int j = m; j >= 0; j--) {
                if (g[j][b] || g[j][b + 1] || g[j][b + 2]) {
                    g[j + 1][b] = 1;
                    g[j + 1][b + 1] = 1;
                    g[j + 1][b + 2] = g[j + 1][b + 2] = 1;
                    // cout << j << ' ' << b << endl;
                    break;
                }
            }
        }
    }
    for (int j = 1; j <= 8; j++) {
        for (int i = m; i >= 0; i--) {
            if (g[i][j]) {
                cout << i << ' ';
                break;
            }
        }
    }
    cout << endl;
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