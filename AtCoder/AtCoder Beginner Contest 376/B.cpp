#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;

int calc(int s, int t, int b) {
    if (s == t) return 0;
    if (t > s) {
        if (t - s < n - (t - s)) {
            if (b < s || b > t) return t - s;
            else return n - (t - s);
        }
    } else {
        if (s - t < n - (s - t)) {
            if (b < t || b > s) return s - t;
            else return n - (s - t);
        }
    }
}

void solve() {
    int q;
    cin >> n >> q;
    int l = 1, r = 2, res = 0;
    for (int i = 0; i < q; i++) {
        char h;
        int t;
        cin >> h >> t;
        if (h == 'L') {
            res += calc(l, t, r);
            l = t;
        } else {
            res += calc(r, t, l);
            r = t;
        }
    }
    cout << res << endl;
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