#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 300005;
int a[maxn];

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int l = 0, r = 0, s0 = 0, s1 = 0, val = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) s1++;
        else s0++;
        r = max(r, s0 - s1 + val);
        val = max(val, s1 - s0);
    }
    s0 = 0; s1 = 0, val = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) s1++;
        else s0++;
        l = max(l, s1 - s0 + val);
        val = max(val, s0 - s1);
    }
    cout << sum + r - (sum - l) + 1 << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

