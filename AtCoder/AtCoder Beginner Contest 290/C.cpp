#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), vst(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] <= n) vst[a[i]] = 1;
    }
    int res = 0;
    while (vst[res]) res++;
    cout << min(k, res) << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}