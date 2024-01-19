#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string S, F;
    cin >> S >> F;
    if (S.size() == 1 && F.size() == 1) {
        if (S == F) cout << 10 << endl;
        else cout << 0 << endl;
    } else {
        for (auto c: S) {
            bool f = false;
            for (auto d: F) {
                if (c == d) f = true;
            }
            if (!f) {
                cout << 0 << endl;
                return;
            }
        }
        cout << 10 << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}