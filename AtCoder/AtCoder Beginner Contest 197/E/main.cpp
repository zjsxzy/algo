#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const LL inf = 1LL << 60;
void solve() {
    int n;
    cin >> n;
    vector<int> x(n), c(n);
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> c[i];
        num.push_back(c[i]);
    }
    num.push_back(0);
    num.push_back(n + 1);
    sort(num.begin(), num.end());
    num.resize(unique(num.begin(), num.end()) - num.begin());
	for (int i = 0; i < n; i++) {
		c[i] = lower_bound(num.begin(), num.end(), c[i]) - num.begin();
	}
    /*
    for (int i = 0; i < n; i++) {
        cout << x[i] << " " << c[i] << endl;
    }
    */
    vector<vector<LL>> G(num.size());
    G[0].push_back(0);
    G[num.size() - 1].push_back(0);
    for (int i = 0; i < n; i++) {
        G[c[i]].push_back(x[i]);
    }
    for (int i = 0; i < num.size(); i++) {
        sort(G[i].begin(), G[i].end());
        if (G[i].size() >= 2) {
            vector<LL> H = {G[i][0], G[i][G[i].size() - 1]};
            G[i] = H;
        }
    }
    vector<vector<LL>> dp(num.size(), vector<LL>(2));
    for (int i = 0; i < num.size(); i++) {
        dp[i][0] = inf;
        dp[i][1] = inf;
    }
    dp[0][0] = 0;
    for (int i = 1; i < num.size(); i++) {
        for (int j = 0; j < G[i - 1].size(); j++) {
            for (int k = 0; k < G[i].size(); k++) {
                if (G[i].size() == 1) {
                    dp[i][k] = min(dp[i][k], dp[i - 1][j] + abs(G[i - 1][j] - G[i][k]));
                }
                if (G[i].size() == 2) {
                    dp[i][k] = min(dp[i][k], dp[i - 1][j] + abs(G[i - 1][j] - G[i][k ^ 1]) + abs(G[i][k ^ 1] - G[i][k]));
                }
            }
        }
    }
    cout << dp[num.size() - 1][0] << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

