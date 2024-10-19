#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, c;
    cin >> n >> c;
    int prev = -1, res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (prev == -1 || x - prev >= c) {
            res++;
            prev = x;
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