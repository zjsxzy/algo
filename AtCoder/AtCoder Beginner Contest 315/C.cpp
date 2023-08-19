#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> f(n), s(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i] >> s[i];
    }
    pair<int, int> mval = {s[0], f[0]};
    int p = 0;
    for (int i = 1; i < n; i++) {
        if (make_pair(s[i], f[i]) > mval) {
            mval = {s[i], f[i]};
            p = i;
        }
    }
    int diff_max = 0, same_max = 0;
    for (int i = 0; i < n; i++) {
        if (i == p) continue;
        if (f[i] == mval.second) {
            if (s[i] > same_max) same_max = s[i];
        } else {
            if (s[i] > diff_max) diff_max = s[i];
        }
    }
    cout << max(mval.first + same_max / 2, mval.first + diff_max) << endl;
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