#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL n, m;
    cin >> n >> m;
    set<pair<int, int>> st;
    vector<int> dx = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        st.insert({x, y});
        for (int k = 0; k < 8; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                st.insert({nx, ny});
            }
        }
    }
    cout << n * n - st.size() << endl;
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