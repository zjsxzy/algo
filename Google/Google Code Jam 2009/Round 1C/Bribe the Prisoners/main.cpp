#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 105;
int P, Q, A[maxn];
int dp[maxn][maxn];

void solve() {
    cin >> P >> Q;
    for (int i = 1; i <= Q; i++) cin >> A[i];

    A[0] = 0;
    A[Q + 1] = P + 1;
    for (int i = 0; i <= Q; i++) dp[i][i + 1] = 0;

    for (int w = 2; w <= Q + 1; w++) {
        for (int i = 0; i + w <= Q + 1; i++) {
            int j = i + w, t = INT_MAX;
            for (int k = i + 1; k < j; k++) {
                t = min(t, dp[i][k] + dp[k][j]);
            }
            dp[i][j] = t + A[j] - A[i] - 2;
        }
    }
    cout << dp[0][Q + 1] << endl;
}

int main() {
    int ts;
    cin >> ts;
    for (int i = 1; i <= ts; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}

