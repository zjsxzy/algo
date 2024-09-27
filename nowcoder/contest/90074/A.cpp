#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 2; i <= n; i++) {
        if (cnt[i] == 0) {
            for (int j = i; j <= n; j += i) {
                cnt[j]++;
            }
        }
    }
    int res = 0;
    for (int i = 2; i <= n; i++) {
        if (cnt[i] > 1) res++;
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