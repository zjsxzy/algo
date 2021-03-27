#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve(int cs) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int res = 0;
    for (int i = 0; i < n - 1; i++) {
        int mn = INT_MAX, mn_pos = -1;
        for (int j = i; j < n; j++) {
            if (a[j] < mn) {
                mn = a[j];
                mn_pos = j;
            }
        }
        res += mn_pos - i + 1;
        reverse(a.begin() + i, a.begin() + mn_pos + 1);
    }
    printf("Case #%d: %d\n", cs, res);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    for (int cs = 1; cs <= ts; cs++) {
        solve(cs);
    }
    return 0;
}

