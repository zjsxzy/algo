#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), s2(n + 1), s5(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int t2 = 0, t5 = 0, x = a[i];
        while (x % 2 == 0) {
            t2++;
            x /= 2;
        }
        while (x % 5 == 0) {
            t5++;
            x /= 5;
        }
        s2[i] = s2[i - 1] + t2;
        s5[i] = s5[i - 1] + t5;
    }
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        auto j2 = lower_bound(s2.begin(), s2.end(), s2[i - 1] + k) - s2.begin();
        auto j5 = lower_bound(s5.begin(), s5.end(), s5[i - 1] + k) - s5.begin();
        int l = max(j2, j5);
        if (l < i) l = i;
        if (l <= n && min(s2[l] - s2[i - 1], s5[l] - s5[i - 1]) == k) {
            j2 = upper_bound(s2.begin(), s2.end(), s2[i - 1] + k) - s2.begin();
            j5 = upper_bound(s5.begin(), s5.end(), s5[i - 1] + k) - s5.begin();
            if (max(j2, j5) - l >= 0) res += max(j2, j5) - l;
        }
    }
    cout << res << endl;
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