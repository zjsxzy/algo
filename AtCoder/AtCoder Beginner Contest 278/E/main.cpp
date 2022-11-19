#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 305;
int a[maxn][maxn];

void solve() {
    int H, W, N, h, w;
    cin >> H >> W >> N >> h >> w;
    set<int> st;
    vector<pair<int, int>> l(N + 1, {0, W + 1}), r(N + 1, {0, 0}), b(N + 1, {0, 0}), t(N + 1, {H + 1, 0});
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            int x;
            cin >> x;
            a[i][j] = x;
            st.insert(x);
            if (i < t[x].first) t[x] = {i, j};
            if (i > b[x].first) b[x] = {i, j};
            if (j < l[x].second) l[x] = {i, j};
            if (j > r[x].second) r[x] = {i, j};
        }
    }
    auto inside = [&](pair<int, int> p, int a, int b) {
        return p.first >= a && p.first < a + h && p.second >= b && p.second < b + w;
    };
    for (int i = 1; i <= H - h + 1; i++) {
        for (int j = 1; j <= W - w + 1; j++) {
            int ans = (int)st.size();
            for (int k = 1; k <= N; k++) {
                if (st.count(k)) {
                    if (inside(l[k], i, j) && inside(r[k], i, j) && inside(b[k], i, j) && inside(t[k], i, j)) ans--;
                }
            }
            cout << ans << ' ';
            if (j == W - w + 1) cout << endl;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

