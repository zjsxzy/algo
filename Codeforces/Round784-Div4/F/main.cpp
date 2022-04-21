#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 200005;
int a[maxn], ls[maxn], rs[maxn];

void solve() {
    int n;
    cin >> n;
    ls[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ls[i] = ls[i - 1] + a[i];
    }
    rs[n + 1] = 0;
    map<int, set<int>> mp;
    for (int i = n; i >= 1; i--) {
        rs[i] = rs[i + 1] + a[i];
        mp[rs[i]].insert(i);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (mp.find(ls[i]) != mp.end()) {
            auto x = mp[ls[i]].lower_bound(i + 1);
            if (x != mp[ls[i]].end()) {
                res = max(res, i + n - *x + 1);
            }
        }
    }
    cout << res << endl;
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

