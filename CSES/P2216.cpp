#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> idx(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        idx[x] = i;
    }
    int res = 1;
    for (int i = 2; i <= n; i++) {
        if (idx[i] < idx[i - 1]) res++;
    }
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