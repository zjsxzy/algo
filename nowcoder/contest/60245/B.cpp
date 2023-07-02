#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    string s;
    std::cin >> s;
    map<int, int> r, b;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') r[a[i]]++;
        else b[a[i]]++;
    }
    LL res = 0;
    for (auto [k, v]: r) {
        res += (LL)v * b[k];
    }
    std::cout << res << endl;
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