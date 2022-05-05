#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string str;
    cin >> str;
    int n = str.size();
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    vector<bool> pref(n), suff(n);
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (str[i] == '0') flag = false;
        pref[i] = flag;
    }
    flag = true;
    for (int i = n - 1; i >= 0; i--) {
        if (str[i] == '1') flag = false;
        suff[i] = flag;
    }
    int res = 0;
    if (suff[1]) res++;
    for (int i = 1; i < n - 1; i++) {
        if (pref[i - 1] && suff[i + 1]) res++;
    }
    if (pref[n - 2]) res++;
    cout << res << endl;
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

