#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    vector<string> s(8);
    for (int i = 0; i < 8; i++) {
        cin >> s[i];
    }
    vector<int> col(8), row(8);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (s[i][j] == '#') {
                row[i] = col[j] = 1;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (!row[i] && !col[j]) res++;
        }
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