#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e6 + 5;
int s[maxn][32];

void solve() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    memset(s, 0, sizeof(s));
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        for (int b = 0; b < 31; b++) {
            if (a[i] >> b & 1) {
                if (i == 0) s[i][b] = 1;
                else s[i][b] = s[i - 1][b] + 1;
            }
        }
    }
    auto range = [&](int i, int j, int b) {
        if (i == 0) return s[j][b];
        return s[j][b] - s[i - 1][b];
    };
    auto check = [&](int i, int j) {
        for (int b = 0; b < 31; b++) {
            if (range(i, j, b) == j - i + 1) return false;
        }
        return true;
    };
    LL res = 0;
    for (int i = 0; i < n; i++) {
        int lo = i, hi = n - 1, j = -1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (check(i, mid)) {
                j = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        if (j != -1) {
            res += n - j;
        }
    }
    std::cout << res << endl;
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