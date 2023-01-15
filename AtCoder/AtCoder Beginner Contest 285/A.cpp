#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int a, b;
    cin >> a >> b;
    if (b / 2 == a) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}