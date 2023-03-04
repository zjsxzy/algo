#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    LL res = 0;
    vector<LL> cnt(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; i * j <= n; j++) {
            cnt[i * j]++;
        }
    }
    for (int ab = 1; ab <= n; ab++) {
        int cd = n - ab;
        res += cnt[ab] * cnt[cd];
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