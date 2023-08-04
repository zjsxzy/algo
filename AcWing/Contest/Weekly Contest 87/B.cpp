#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        vector<int> b;
        for (int j = 1; j <= i; j++) b.push_back(a[j]);
        sort(b.begin(), b.end());
        reverse(b.begin(), b.end());
        int t = 0;
        for (int j = 0; j < i; j+=2) {
            t += b[j];
        }
        if (t > m) {
            cout << i - 1 << endl;
            return;
        }
    }
    cout << n << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}