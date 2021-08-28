/*
ID: frankzh1
TASK: numtri
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> num(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cin >> num[i][j];
        }
    }
    vector<int> f(n);
    for (int j = 0; j < n; j++) {
        f[j] = num[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--) {
        vector<int> g(n);
        for (int j = 0; j < i + 1; j++) {
            g[j] = max(f[j], f[j + 1]) + num[i][j];
        }
        for (int j = 0; j < i + 1; j++) {
            f[j] = g[j];
        }
    }
    cout << f[0] << endl;
}

int main() {
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);
    solve();
    return 0;
}

