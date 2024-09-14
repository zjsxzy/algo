#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> vst(n + 1);
    for (int i = 0; i < m; i++) {
        int x;
        char c;
        cin >> x >> c;
        if (!vst[x] && c == 'M') {
            cout << "Yes" << endl;
            vst[x] = true;
        } else {
            cout << "No" << endl;
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