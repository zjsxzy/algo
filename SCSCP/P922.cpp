#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges.emplace_back(a, b);
    }
    int res = 0;
    for (int i = 0; i < (1 << m); i++) {
        vector<int> deg(n + 1);
        for (int j = 0; j < m; j++) {
            if (i >> j & 1) {
                deg[edges[j].first]++;
            } else {
                deg[edges[j].second]++;
            }
        }
        bool flag = true;
        for (int j = 1; j <= n; j++) {
            if (deg[j] != 1) {
                flag = false;
                break;
            }
        }
        res += flag;
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