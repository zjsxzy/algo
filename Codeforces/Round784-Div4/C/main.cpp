#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> odd(2), even(2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i & 1) {
            odd[a[i] % 2]++;
        } else {
            even[a[i] % 2]++;
        }
    }
    for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
            if (odd[a] == 0 && even[b] == 0) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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

