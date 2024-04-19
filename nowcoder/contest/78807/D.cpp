#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    string S;
    cin >> n >> S;
    const int mod = 1e9 + 7;
    int res = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        if ((S[i] - '0') % 2 == 0) {
            res += sum + 1;
            res %= mod;
        }
        sum = sum * 2 + (S[i] != '0');
        sum %= mod;
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