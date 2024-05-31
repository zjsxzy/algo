#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m = 0;
    for (auto c: s) m += (c == '1');
    s += s;
    int res = n;
    for (int i = 0, j = 0, cnt = 0; i < n; i++) {
        while (j < s.size() && cnt < m) {
            cnt += s[j] == '1';
            j++;
        }
        res = min(res, j - i - m);
        cnt -= s[i] == '1';
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