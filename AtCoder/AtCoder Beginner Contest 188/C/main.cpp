#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(1 << n), b(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        cin >> a[i];
        b[i] = i;
    }
    int m = (1 << n);
    while (m) {
        if (m == 2) {
            if (a[b[0]] > a[b[1]]) cout << b[1] + 1 << endl;
            else cout << b[0] + 1 << endl;
            break;
        }
        vector<int> t;
        for (int i = 0; i < m - 1; i += 2) {
            if (a[b[i]] > a[b[i + 1]]) t.push_back(b[i]);
            else t.push_back(b[i + 1]);
        }
        /*
        for (auto &x : t) {
            cout << x << " ";
        }
        cout << endl;
        */
        b = t;
        m >>= 1;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

