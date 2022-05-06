#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string a, b;
    cin >> a >> b;
    string res;
    int n = a.size(), m = b.size();
    for (int i = 0; i < max(n, m); i++) {
        if (i >= n) res += b[i];
        else if (i >= m) res += a[i];
        else res += (char)(((a[i] - '0') + (b[i] - '0')) % 3 + '0');
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

