#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int mod = 1e9 + 7;
    LL curr = 1;
    LL res = 0;
    for (auto c: b) {
        LL t = (c - '0') * curr % mod;
        res += t;
        res %= mod;
        curr *= 10;
        curr %= mod;
    }
    for (auto c: a) {
        LL t = (c - '0') * curr % mod;
        res += t;
        res %= mod;
        curr *= 10;
        curr %= mod;
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