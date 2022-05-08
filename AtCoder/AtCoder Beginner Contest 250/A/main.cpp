#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int h, w, r, c;
    cin >> h >> w >> r >> c;
    int res = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (abs(i - r) + abs(j - c) == 1) res++;
        }
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

