#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    int st;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == -1) st = i;
        else p[x] = i;
    }
    cout << st;
    while (p[st] != 0) {
        cout << " " << p[st];
        st = p[st];
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