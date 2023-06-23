#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    int steps = 0;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        steps += a[i];
    }
    for (int i = 0, pos = 0; i < steps; i++) {
        if (pos == 0) {
            std::cout << 'R';
            pos++;
            a[pos]--;
        } else if (pos == n) {
            std::cout << 'L';
            a[pos]--;
            pos--;
        } else if (a[pos + 1] >= a[pos]) {
            std::cout << 'R';
            pos++;
            a[pos]--;
        } else {
            std::cout << 'L';
            a[pos]--;
            pos--;
        }
    }
    std::cout << endl;
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