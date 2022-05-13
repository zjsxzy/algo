#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    string s0, s1;
    cin >> s0 >> s1;
    int cnt = 0, l = n, r = 0, last = -1;
    for (int i = 0; i < n; i++) {
        if (s0[i] == '*' || s1[i] == '*') {
            l = min(l, i);
            r = max(r, i);
            if (s0[i] == '*' && s1[i] == '*') {
                cnt++;
                last = -1;
            } else if (last == -1) {
                last = s1[i] == '*';
            } else if ((s1[i] == '*') ^ last) {
                cnt++;
                last = -1;
            }
        }
    }
    cout << r - l + cnt << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

