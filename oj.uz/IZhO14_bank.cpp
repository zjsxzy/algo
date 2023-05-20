#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto& x: a) cin >> x;
    for (auto& x: b) cin >> x;
    vector covered(1 << m, -1), left(1 << m, -1);
    covered[0] = 0;
    left[0] = 0;
    for (int i = 0; i < (1 << m); i++) {
        if (covered[i] == -1) continue;
        int target = a[covered[i]];
        for (int j = 0; j < m; j++) {
            if (!(i >> j & 1)) {
                if (left[i] + b[j] == target && covered[i] + 1 >= covered[i | (1 << j)]) {
                    covered[i | (1 << j)] = covered[i] + 1;
                    left[i | (1 << j)] = 0;
                } else if (left[i] + b[j] < target && covered[i] >= covered[i | (1 << j)]) {
                    covered[i | (1 << j)] = covered[i];
                    left[i | (1 << j)] = left[i] + b[j];
                }
            }
        }
        if (covered[i] == n) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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