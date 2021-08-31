/*
ID: frankzh1
TASK: shopping
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 10;
int dp[MAXN][MAXN][MAXN][MAXN][MAXN];

void solve() {
    int n, m, cnt = 0;
    cin >> n;
    vector<vector<pair<int, int>>> vc(n);
    vector<int> price(n);
    map<int, int> idx;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x, y;
            cin >> x >> y;
            if (idx.find(x) == idx.end()) {
                idx[x] = cnt;
                cnt++;
            }
            vc[i].emplace_back(idx[x], y);
        }
        cin >> price[i];
    }

    cin >> m;
    int maxm = max(m, 5);
    vector<int> v(maxm), w(maxm); // nums, original price
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (idx.find(x) == idx.end()) {
            idx[x] = cnt;
            cnt++;
        }
        cin >> v[idx[x]] >> w[idx[x]];
    }

    for (int i = 0; i <= v[0]; i++) {
        for (int j = 0; j <= v[1]; j++) {
            for (int k = 0; k <= v[2]; k++) {
                for (int l = 0; l <= v[3]; l++) {
                    for (int o = 0; o <= v[4]; o++) {
                        dp[i][j][k][l][o] = i * w[0] + j * w[1] + k * w[2] + l * w[3] + o * w[4];
                        for (int I = 0; I < n; I++) {
                            vector<int> nums(maxm);
                            for (int J = 0; J < vc[I].size(); J++) {
                                nums[vc[I][J].first] = vc[I][J].second;
                            }
                            if (i >= nums[0] && j >= nums[1] && k >= nums[2] && l >= nums[3] && o >= nums[4]) {
                                dp[i][j][k][l][o] = min(dp[i][j][k][l][o], dp[i-nums[0]][j-nums[1]][k-nums[2]][l-nums[3]][o-nums[4]] + price[I]);
                            }
                        }
                    }
                }
            }
        }
    }
    cout << dp[v[0]][v[1]][v[2]][v[3]][v[4]] << endl;
}

int main() {
    freopen("shopping.in", "r", stdin);
    freopen("shopping.out", "w", stdout);
    solve();
    return 0;
}

