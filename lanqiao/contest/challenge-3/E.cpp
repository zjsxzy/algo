#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<LL> a(n + 1), s(n + 1), sq(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] + a[i], sq[i] = sq[i - 1] + a[i] * a[i];
    auto check = [&](LL x) {
        int sum = 0;
        for (int i = 1; i <= n; ) {
            int lo = i, hi = n, p;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                LL t = (s[mid] - s[i - 1]) * (s[mid] - s[i - 1]) - (sq[mid] - sq[i - 1]);
                // cout << mid << ' ' << t / 2 << endl;
                if (t / 2 <= x) p = mid, lo = mid + 1;
                else hi = mid - 1;
            }
            sum++;
            i = p + 1;
        }
        return sum <= m;
    };
    LL lo = 0, hi = 4e18, res;
    while (lo <= hi) {
        LL mid = (lo + hi) >> 1;
        if (check(mid)) {
            res = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
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