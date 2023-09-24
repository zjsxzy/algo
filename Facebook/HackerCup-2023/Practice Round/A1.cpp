#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve(int cs) {
    cout << "Case #" << cs << ": ";
    int s, d, k;
    cin >> s >> d >> k;
    int a = k, b = k + 1;
    if (s + 2 * d >= a && 2 * (s + d) >= k + 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve(t);
    }
    return 0;
}