/*
ID: frankzh1
TASK: money
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int v, n;
    cin >> v >> n;
    vector<int> coin(v);
    for (auto &x: coin) {
        cin >> x;
    }
    vector<LL> f(n + 1);
    f[0] = 1;
    for (int i = 0; i < v; i++) {
        vector<LL> g(n + 1);
        for (int j = 0; j <= n; j++) {
            g[j] = f[j];
            if (j - coin[i] >= 0) {
                g[j] += g[j - coin[i]];
            }
        }
        f = g;
    }
    cout << f[n] << endl;
}

int main() {
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    solve();
    return 0;
}

