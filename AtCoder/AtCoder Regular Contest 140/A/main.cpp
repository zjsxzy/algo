#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int l = 1; l < n; l++) {
        if (n % l != 0) continue;
        int cnt = 0;
        for (int i = 0; i < l; i++) {
            map<char, int> mp;
            for (int j = i; j < n; j += l) {
                mp[s[j]]++;
            }
            int mx = 0;
            for (auto [k, v]: mp) {
                mx = max(mx, v);
            }
            cnt += n / l - mx;
        }
        if (cnt <= k) {
            cout << l << endl;
            return;
        }
    }
    cout << n << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}


