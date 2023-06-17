#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    for (auto c: s) {
        cout << c << c;
    }
    cout << endl;
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