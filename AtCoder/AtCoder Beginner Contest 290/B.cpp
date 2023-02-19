#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (cnt >= k) {
            cout << 'x';
            continue;
        }
        cout << s[i];
        cnt += (s[i] == 'o');
    }
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