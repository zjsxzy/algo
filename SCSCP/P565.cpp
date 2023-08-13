#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    LL prev = a[0], curr = 0;
    int res = 1;
    for (int i = 1; i < n; i++) {
        curr += a[i];
        if (curr >= prev) {
            res++;
            prev = curr;
            curr = 0;
        }
    }
    cout << res << endl;
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