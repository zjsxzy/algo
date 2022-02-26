#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    vector<int> a(10);
    for (auto& x: a) cin >> x;
    int cur = 0;
    for (int i = 0; i < 2; i++) {
        cur = a[cur];
    }
    cout << a[cur] << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

