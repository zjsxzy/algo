#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> vst(w + 1);
    for (int i = 0; i < n; i++) {
        if (a[i] <= w) vst[a[i]] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] + a[j] <= w) vst[a[i] + a[j]] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[i] + a[j] + a[k] <= w) vst[a[i] + a[j] + a[k]] = 1;
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= w; i++) if (vst[i]) res++;
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

