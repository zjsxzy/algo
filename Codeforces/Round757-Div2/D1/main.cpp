#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 5000005;
const int M = 5000000;
int cnt[maxn];
LL dp[maxn];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x: a) {
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= M; i++) {
        for (int j = i * 2; j <= M; j += i) {
            cnt[i] += cnt[j];
        }
        // if (i <= 10) cout << i << " " << cnt[i] << endl;
    }
    LL res = 0;
    dp[1] = cnt[1];
    for (int i = 1; i <= M; i++) {
        for (int j = i * 2; j <= M; j += i) {
            dp[j] = max(dp[j], dp[i] + (LL)cnt[j] * (j - i));
        }
        res = max(res, dp[i]);
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

