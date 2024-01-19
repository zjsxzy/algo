#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a * d < b * c) cout << 'Y' << endl;
    else cout << 'S' << endl;    
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