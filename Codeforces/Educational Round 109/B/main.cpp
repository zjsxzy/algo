#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (a[i] != i + 1) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << 0 << endl;
        return;
    }
    if (a[0] == 1 || a[n - 1] == n) {
        cout << 1 << endl;
        return;
    }
    if (a[0] == n && a[n - 1] == 1) {
        cout << 3 << endl;
        return;
    }
    cout << 2 << endl;
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

