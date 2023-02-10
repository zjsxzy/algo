#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    s.resize(k);
    sort(s.begin(), s.end());
    for (int i = 0; i < k; i++) cout << s[i] << endl;
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