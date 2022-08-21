#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL inf = 1ll << 60;
int N, P, M, Ar, Ac;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
LL dp[25][15][15][1 << 11];
int x[15], y[15], c[15];
pair<char, int> cost[5];
int customer[15][15], idx[15][15];

LL calc(LL coin, pair<char, int> f) {
    if (f.first == '+') {
        return coin + f.second;
    } else if (f.first == '-') {
        return coin - f.second;
    } else if (f.first == '*') {
        return coin * f.second;
    }
    return floor((float)coin / f.second);
}

void solve() {
    cin >> N >> P >> M >> Ar >> Ac;
    for (int i = 0; i < 4; i++) {
        cin >> cost[i].first >> cost[i].second;
    }
    memset(customer, 0, sizeof(customer));
    for (int i = 0; i < P; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        customer[x][y] = c;
        idx[x][y] = i;
    }
    for (int m = 0; m <= M; m++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                for (int s = 0; s < (1 << P); s++) {
                    dp[m][i][j][s] = -inf;
                }
            }
        }
    }
    dp[0][Ar][Ac][0] = 0;
    for (int m = 0; m < M; m++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                for (int s = 0; s < (1 << P); s++) {
                    if (dp[m][i][j][s] == -inf) continue;
                    LL t = dp[m][i][j][s];
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k], nj = j + dy[k];
                        if (ni >= 1 && ni <= N && nj >= 1 && nj <= N) {
                            LL nt = calc(t, cost[k]);
                            if (nt > dp[m + 1][ni][nj][s]) {
                                dp[m + 1][ni][nj][s] = nt;
                            }
                            if (customer[ni][nj] > 0 && !(s >> idx[ni][nj] & 1)) {
                                if (nt + customer[ni][nj] > dp[m + 1][ni][nj][s | (1 << idx[ni][nj])]) {
                                    dp[m + 1][ni][nj][s | (1 << idx[ni][nj])] = nt + customer[ni][nj];
                                }
                            }
                        }
                    }
                    if (t > dp[m + 1][i][j][s]) {
                        dp[m + 1][i][j][s] = t;
                    }
                }
            }
        }
    }
    int pi = 1, pj = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dp[M][i][j][(1 << P) - 1] > dp[M][pi][pj][(1 << P) - 1]) {
                pi = i;
                pj = j;
            }
        }
    }
    LL res = dp[M][pi][pj][(1 << P) - 1];
    if (res == -inf) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << dp[M][pi][pj][(1 << P) - 1] << endl;
}

int main() {
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       cout << "Case #" << t << ": ";
       solve();
   }
   return 0;
}

