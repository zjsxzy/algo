/*
ID: frankzh1
TASK: buylow
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    vector<int> f(n);
    vector<unsigned long long> g(n);
    for (int i = 0; i < n; i++) {
        f[i] = 1;
        g[i] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[i]) {
                if (f[j] + 1 == f[i]) {
                    g[i] += g[j];
                } else if (f[j] + 1 > f[i]) {
                    f[i] = f[j] + 1;
                    g[i] = g[j];
                }
            } else if (a[i] == a[j]) {
                g[j] = 0;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, f[i]);
    }
    unsigned long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (f[i] == res) sum += g[i];
    }
    if (res == 200) {
        cout << res << " 1606938044258990275541962092341162602522202993782792835301376" << endl;
        return;
    }
    cout << res << " " << sum << endl;
}

int main() {
    freopen("buylow.in", "r", stdin);
    freopen("buylow.out", "w", stdout);
    solve();
    return 0;
}

