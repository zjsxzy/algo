#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> cnt(n), removed(n);
    while (q--) {
        int t, x;
        cin >> t >> x;
        x--;
        if (t == 1) {
            cnt[x]++;
            if (cnt[x] >= 2) removed[x] = 1;
        } else if (t == 2) {
            removed[x] = 1;
        } else {
            if (removed[x]) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
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