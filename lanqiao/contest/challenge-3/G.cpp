#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 5;
int n;
int a[maxn], fib[30], f[maxn][30];

int dp(int x, int y) {
    if (f[x][y] != -1) return f[x][y];
    int ans = 0;
    for (int i = y + 1; i < 30; i++) {
        if (x - fib[i] >= 0 && a[x] < a[x - fib[i]] && !dp(x - fib[i], i)) {
            ans = 1;
            break;
        }
        if (x + fib[i] < n && a[x] < a[x + fib[i]] && !dp(x + fib[i], i)) {
            ans = 1;
            break;
        }
    }
    return f[x][y] = ans;
};

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    fib[0] = 1; fib[1] = 1;
    for (int i = 2; i < 30; i++) fib[i] = fib[i - 1] + fib[i - 2];
    memset(f, -1, sizeof(f));
    for (int i = 0; i < n; i++) {
        cout << (dp(i, 0) ? "Little Lan" : "Little Qiao") << endl;
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