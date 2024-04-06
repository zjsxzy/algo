#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    map<int, int> color;
    for (int i = 0; i < n; i++) {
        int a, c;
        cin >> a >> c;
        if (color.find(c) == color.end()) color[c] = a;
        else color[c] = min(color[c], a);
    }
    int res = 0;
    for (auto [k, v]: color) res = max(res, v);
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