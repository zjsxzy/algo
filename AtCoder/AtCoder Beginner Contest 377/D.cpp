#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i].first >> vec[i].second;
    }
    sort(vec.begin(), vec.end());
    int l = vec[0].first, r = vec[0].second;
    int L = 1, R;
    LL res = 0;
    for (int i = 1; i < n; ) {
        while (i < n && vec[i].first == l) {
            r = vec[i].second;
            i++;
        }
        // outside
        if (l > L) {
            LL len = l - L - 1;
            LL curr = len * (len + 1) / 2 + 1;
            res += curr;
        }

        // inside
        LL len = r - l + 1;
        LL curr = len * (len + 1) / 2 - 1;
        cout << l << ' ' << r << ' ' << len << ' ' << curr << endl;
        res += curr;
        L = r;
        l = vec[i].first, r = vec[i].second;
    }
    // last outside
    if (m > L) {
        LL len = m - L;
        res += len * (len + 1) / 2 + 1;
    }
    cout << res << endl;
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