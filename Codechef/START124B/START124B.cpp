#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    int s = 0;
    while (n) {
        s += n & 1;
        n >>= 1;
    }
    if (s & 1) cout << "ODD" << endl;
    else cout << "EVEN" << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}