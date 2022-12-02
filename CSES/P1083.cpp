#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> vst(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x; cin >> x;
        vst[x] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (!vst[i]) {
            cout << i << endl;
            return;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

