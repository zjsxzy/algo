#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int a, b;
    cin >> a >> b;
    LL res = 1;
    for (int i = 0; i < b; i++) res *= a;
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