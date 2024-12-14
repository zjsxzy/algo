#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    char c1, c2;
    cin >> n >> c1 >> c2;
    string S;
    cin >> S;
    for (auto& c: S) {
        if (c != c1) c = c2;
    }
    cout << S << '\n';
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