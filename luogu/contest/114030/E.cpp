#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    std::cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        if (b == 0) res += 10;
        else res += a;
    }
    std::cout << res << endl;
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