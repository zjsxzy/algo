#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 55;
bool f[maxn][maxn][1005];
int g[maxn][maxn][1005];

void solve() {
    int n, b, p, k;
    cin >> n >> b >> p >> k;
    vector<int> B(n + 1);
    B[0] = 1;
    for (int i = 1; i <= n; i++) B[i] = (LL)B[i - 1] * b % p;
    string s;
    cin >> s;
    int m = 0;
    for (int i = 0; i < n; i++) {
        m = (m + (LL)B[n - i - 1] * (s[i] - 'a' + 1)) % p;
    }
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    f[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int t = 0; t < p; t++) {
                if (!f[i][j][t]) continue;
                for (int c = 1; c <= 26; c++) {
                    int nt = (t + (LL)B[n - i - 1] * c) % p;
                    if (j < n && s[i] - 'a' + 1 == c) {
                        f[i + 1][j + 1][nt] = 1;
                        g[i + 1][j + 1][nt] = c;
                    } else {
                        f[i + 1][j][nt] = 1;
                        g[i + 1][j][nt] = c;
                    }
                }
            }
        }
    }
    if (!f[n][k][m]) cout << -1 << endl;
    else {
        string t;
        for (int i = n; i > 0; i--) {
            int c = g[i][k][m];
            t += (char)('a' + c - 1);
            if (c == s[i - 1] - 'a' + 1) k--;
            m = (m - (LL)B[n - i] * c % p + p) % p;
        }
        reverse(t.begin(), t.end());
        cout << t << endl;
    }
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