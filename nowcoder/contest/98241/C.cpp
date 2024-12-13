#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

unsigned seed;
unsigned rnd(){
	unsigned ret=seed;
	seed^=seed<<13;
	seed^=seed>>17;
	seed^=seed<<5;
	return ret;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k >> seed;
    vector p(n + 1, vector<int>(m + 1));
    vector<int> vst(m + 1, 0);
    vector<set<int>> plant(m + 1);
    while (k--) {
        int op = (rnd() % 2) + 1;
        if (op == 1) {
            int j, x;
            j = (rnd() % m) + 1;
            x = (rnd() % (n * m)) + 1;
            if (!vst[j]) {
                for (int i = 1; i <= n; i++) {
                    p[i][j] = x;
                }
                vst[j] = 1;
            } else {
                for (auto i: plant[j]) {
                    p[i][j] = x;
                }
                plant[j].clear();
            }
            // cout << op << ' ' << j << ' ' << x << '\n';
        } else {
            int a, b;
            a = (rnd() % n) + 1;
            b = (rnd() % m) + 1;
            if (p[a][b]) {
                p[a][b] = 0;
                plant[b].insert(a);
            }
            // cout << op << ' ' << a << ' ' << b << '\n';
        }
    }
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // cout << p[i][j] << ' ';
            res ^= (LL)p[i][j] * ((i - 1) * m + j);
        }
        // cout << '\n';
    }
    cout << res << '\n';
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