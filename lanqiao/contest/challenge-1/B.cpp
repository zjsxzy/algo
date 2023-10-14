#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, q;
    cin >> n >> q;
    while (q--) {
        string s;
        cin >> s;
        LL curr = 1;
        for (auto c: s) {
            if (c == 'R') curr *= 2;
            else curr = curr * 2 - 1;
        }
        cout << curr << endl;
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