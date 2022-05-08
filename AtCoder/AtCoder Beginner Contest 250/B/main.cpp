#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
        for (int t = 0; t < a; t++) {
            for (int j = 0; j < n; j++) {
                for (int s = 0; s < b; s++) {
                    if ((i + j) & 1) cout << "#";
                    else cout << ".";
                }
            }
            cout << endl;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

