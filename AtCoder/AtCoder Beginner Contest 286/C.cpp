#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    LL a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    LL res = 1ll << 60;
    for (int i = 0; i < n; i++) {
        string t = s.substr(i, n - i) + s.substr(0, i);
        LL curr = a * i;
        for (int j = 0; j < n / 2; j++) {
            curr += b * (t[j] != t[n - j - 1]);
        }
        res = min(res, curr);
    }
    cout << res << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}