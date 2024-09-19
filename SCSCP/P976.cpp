#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        l1--; r1--; l2--; r2--;
        LL res = 0;
        map<int, int> cnt;
        for (int i = l1; i <= r1; i++) {
            cnt[a[i]]++;
        }
        for (int i = l2; i <= r2; i++) {
            if (cnt.find(a[i]) != cnt.end()) {
                res += cnt[a[i]];
            }
        }
        cout << res << endl;
    }
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