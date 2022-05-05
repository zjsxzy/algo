#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++) a[i] = str[i] - 'a';
    for (int i = 0; i < n; i++) {
        if (a[i] <= k) {
            mx = max(mx, a[i]);
        } else {
            int l = a[i] - (k - mx);
            int r = a[i];
            for (int j = 0; j < n; j++) {
                if (l <= a[j] && a[j] <= r) {
                    a[j] = l;
                }
            }
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] <= mx) a[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        cout << (char)(a[i] + 'a');
    }
    cout << endl;
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

