#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;


void solve() {
    int n;
    cin >> n;
    LL res = (LL)n * (n - 1) * (n - 2) / 6;
    vector<pair<int, int>> v(n);
    map<int, int> cnta, cntb;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        cnta[v[i].first]++;
        cntb[v[i].second]++;
    }
    LL sum = 0;
    for (int i = 0; i < n; i++) {
        int a = v[i].first, b = v[i].second;
        LL ca = cnta[a], cb = cntb[b];
        if (ca > 1 && cb > 1) {
            sum += (ca - 1) * (cb - 1);
        }
    }
    cout << res - sum << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

