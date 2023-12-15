#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    auto t = p;
    sort(t.begin(), t.end());
    multiset<int> ls, rs;
    for (int i = 1; i <= n / 2; i++) ls.insert(t[i]);
    for (int i = n / 2 + 1; i <= n; i++) rs.insert(t[i]);
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        int val = p[x];
        if (ls.find(val) != ls.end()) {
            ls.extract(val);
            if (rs.size() >= ls.size() + 2) {
                ls.insert(*rs.begin());
                rs.extract(*rs.begin());
            }
        } else {
            rs.extract(val);
            if (ls.size() > rs.size()) {
                rs.insert(*ls.rbegin());
                ls.extract(*ls.rbegin());
            }
        }
        if (ls.size() == rs.size()) {
            double ans = *ls.rbegin() + *rs.begin();
            cout << fixed << setprecision(1) << ans / 2 << ' ';
        } else {
            double ans = *rs.begin();
            cout << fixed << setprecision(1) << ans << ' ';
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