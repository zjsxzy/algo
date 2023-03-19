#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL L;
    int n1, n2;
    cin >> L >> n1 >> n2;
    vector<pair<LL, LL>> v1, v2;
    for (int i = 0; i < n1; i++) {
        LL v, l;
        cin >> v >> l;
        v1.push_back({v, l});
    }
    for (int i = 0; i < n2; i++) {
        LL v, l;
        cin >> v >> l;
        v2.push_back({v, l});
    }
    LL l = v1[0].second, r = v2[0].second, i = 0, j = 0;
    LL va = v1[i].first, vb = v2[j].first;
    LL res = 0;
    if (va == vb) res += min(l, r);
    while (1) {
        if (l < r) {
            i++;
            if (i == n1) break;
            va = v1[i].first;
            if (va == vb) {
                res += min(l + v1[i].second, r) - l;
            }
            l += v1[i].second;
        } else {
            j++;
            if (j == n2) break;
            vb = v2[j].first;
            if (va == vb) {
                res += min(r + v2[j].second, l) - r;
            }
            r += v2[j].second;
        }
        // cout << l << ' ' << va << ' ' << r << ' ' << vb << ' ' << res << endl;
    }
    while (i < n1) {
        i++;
        if (i == n1) break;
        if (v1[i].first == vb) res += v1[i].second;
    }
    while (j < n2) {
        j++;
        if (j == n2) break;
        if (v2[i].first == va) res += v2[i].second;
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