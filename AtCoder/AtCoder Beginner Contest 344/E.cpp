#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> next, prev;
    for (int i = 0; i < n - 1; i++) {
        next[a[i]] = a[i + 1];
        prev[a[i + 1]] = a[i];
    }
    next[a[n - 1]] = -1;
    prev[a[0]] = -1;
    int start = a[0];
    auto output = [&](int x) {
        while (x != -1) {
            cout << x << ' ';
            x = next[x];
        }
        cout << endl;
    };
    int q;
    cin >> q;
    while (q--) {
        int t, x, y;
        cin >> t;
        if (t == 1) {
            cin >> x >> y;
            int nxt = next[x];
            prev[y] = x;
            next[x] = y;
            next[y] = nxt;
            prev[nxt] = y;
        } else {
            cin >> x;
            if (prev[x] == -1) start = next[x];
            prev[next[x]] = prev[x];
            next[prev[x]] = next[x];
            prev.erase(x);
            next.erase(x);
        }
        // output(start);
    }
    output(start);
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