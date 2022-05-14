#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int w;
    cin >> w;
    cout << 300 << endl;
    for (int i = 1; i <= 100; i++) {
        cout << i << " " << i * 100 << " " << i * 10000 << " ";
    }
    cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

