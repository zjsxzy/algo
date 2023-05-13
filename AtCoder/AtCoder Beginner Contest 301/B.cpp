#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    cout << a[0];
    for (int i = 1; i < n; i++) {
        if (abs(a[i] - a[i - 1]) == 1) {
            cout << ' ' << a[i];
        } else {
            if (a[i] > a[i - 1]) {
                for (int j = a[i - 1] + 1; j < a[i]; j++) cout << ' ' << j;
            } else {
                for (int j = a[i - 1] - 1; j > a[i]; j--) cout << ' ' << j;
            }
            cout << ' ' << a[i];
        }
    }
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