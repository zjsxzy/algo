#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 0; i < 4 * n - 1; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i] != 4) {
            cout << i << endl;
            return;
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

