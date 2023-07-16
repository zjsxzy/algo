#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int res = INT_MAX;
    for (int i = 0; i < 26; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            int x = s[j] - 'a';
            sum += min(abs(x - i), min(26 - x + i, 26 - i + x));
        }
        // cout << i << ' ' << sum << endl;
        res = min(res, sum);
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