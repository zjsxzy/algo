/*
ID: frankzh1
TASK: prime3
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 100000;
bool prime[maxn];
int n;
bool dp[10][10][10][10][10];

void checkPrime() {
    for (int i = 2; i < maxn; i++) prime[i] = true;
    for (int i = 2; i < maxn / 2; i++) {
        if (prime[i]) {
            for (int j = 2; i * j < maxn; j++) {
                prime[i * j] = false;
            }
        }
    }
}

bool cmp(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (a[i][j] < b[i][j]) return true;
            if (a[i][j] > b[i][j]) return false;
        }
    }
    return false;
}

void solve() {
    checkPrime();
    int target, first;
    cin >> target >> first;
    memset(dp, false, sizeof(dp));
    vector<int> num(5);
    vector<vector<int>> pri; // possible primes
    for (int i = 10000; i < maxn; i++) {
        if (prime[i]) {
            int x = i, j = 4, sum = 0;
            while (x) {
                num[j--] = x % 10;
                sum += x % 10;
                x /= 10;
            }
            if (sum != target) continue;
            dp[num[0]][num[1]][num[2]][num[3]][num[4]] = true;
            if (num[0] == first) pri.emplace_back(num);
        }
    }

    vector<vector<int>> ans(5, vector<int>(5));
    vector<vector<vector<int>>> total;
    for (int a = 0; a < pri.size(); a++) {
        for (int i = 0; i < 5; i++) ans[0][i] = pri[a][i]; // row 1
        for (int b = 0; b < pri.size(); b++) {
            for (int i = 0; i < 5; i++) ans[i][0] = pri[b][i]; // col 1
            for (int c = 0; c < pri.size(); c++) {
                for (int i = 0; i < 5; i++) ans[i][i] = pri[c][i]; // diagnal
                int sumd = target - ans[4][0] - ans[2][2] - ans[0][4]; // inverse diagnal
                for (int d = 0; d < 10; d++) {
                    if (sumd - d > 9 || sumd - d < 0) continue;
                    if (!dp[ans[4][0]][d][ans[2][2]][sumd - d][ans[0][4]]) continue;
                    ans[3][1] = d;
                    ans[1][3] = sumd - d;
                    int sume = target - ans[1][0] - ans[1][1] - ans[1][3];
                    for (int e = 0; e < 10; e++) {
                        if (sume - e > 9 || sume - e < 0) continue;
                        if (!dp[ans[1][0]][ans[1][1]][e][ans[1][3]][sume - e]) continue;
                        ans[1][2] = e;
                        ans[1][4] = sume - e;
                        int sumf = target - ans[3][0] - ans[3][1] - ans[3][3];
                        for (int f = 0; f < 10; f++) {
                            if (sumf - f > 9 || sumf - f < 0) continue;
                            if (!dp[ans[3][0]][ans[3][1]][f][ans[3][3]][sumf - f]) continue;
                            ans[3][2] = f;
                            ans[3][4] = sumf - f;
                            int sumg = target - ans[0][1] - ans[1][1] - ans[3][1];
                            for (int g = 0; g < 10; g++) {
                                if (sumg - g > 9 || sumg - g < 0) continue;
                                if (!dp[ans[0][1]][ans[1][1]][g][ans[3][1]][sumg - g]) continue;
                                ans[2][1] = g;
                                ans[4][1] = sumg - g;
                                int sumh = target - ans[0][3] - ans[1][3] - ans[3][3];
                                for (int h = 0; h < 10; h++) {
                                    if (sumh - h > 9 || sumh - h < 0) continue;
                                    if (!dp[ans[0][3]][ans[1][3]][h][ans[3][3]][sumh - h]) continue;
                                    ans[2][3] = h;
                                    ans[4][3] = sumh - h;
                                    ans[4][2] = target - ans[0][2] - ans[1][2] - ans[2][2] - ans[3][2];
                                    if (ans[4][2] > 9 || ans[4][2] < 0) continue;
                                    if (!dp[ans[0][2]][ans[1][2]][ans[2][2]][ans[3][2]][ans[4][2]]) continue;
                                    if (!dp[ans[4][0]][ans[4][1]][ans[4][2]][ans[4][3]][ans[4][4]]) continue;
                                    ans[2][4] = target - ans[2][0] - ans[2][1] - ans[2][2] - ans[2][3];
                                    if (ans[2][4] > 9 || ans[2][4] < 0) continue;
                                    if (!dp[ans[2][0]][ans[2][1]][ans[2][2]][ans[2][3]][ans[2][4]]) continue;
                                    if (!dp[ans[0][4]][ans[1][4]][ans[2][4]][ans[3][4]][ans[4][4]]) continue;
                                    total.push_back(ans);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    sort(total.begin(), total.end(), cmp);
    for (int t = 0; t < total.size(); t++) {
        if (t != 0) cout << endl;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << total[t][i][j];
            }
            cout << endl;
        }
    }
    if (total.size() == 0) cout << "NONE" << endl;
}

int main() {
    freopen("prime3.in", "r", stdin);
    freopen("prime3.out", "w", stdout);
    solve();
    return 0;
}

