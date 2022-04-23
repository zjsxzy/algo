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
    map<int, LL> cnt;
    for (auto& x: a) {
        cin >> x;
        cnt[x]++;
    }
    sort(a.begin(), a.end());
    LL res = 0;
    for (int k = 0; k < n; k++) {
        for (int x = 1; x <= (int)sqrt(a[k]); x++) {
            if (a[k] % x != 0) continue;
            if (cnt.find(x) != cnt.end()) {
                int d = a[k] / x;
                if (cnt.find(d) != cnt.end()) {
                    if (d == x) res += cnt[x] * cnt[d];
                    else res += cnt[x] * cnt[d] * 2;
                }
            }
        }
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

