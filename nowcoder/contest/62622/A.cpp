#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    int res = 0;
    for (auto c: s) {
        if (c == '8') res += 2;
        else if (c == '0' || c == '6' || c == '9') res++;
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