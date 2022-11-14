#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 100005;
const int inf = 1e9;
int dp[maxn];

void solve(int mx) {
    for (int i = 1; i <= 1e5; i++) dp[i] = inf;
    dp[1] = 1;
    for (int i = 1; i <= 1e5; i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        int c = 4;
        for (int j = i + i; j <= 1e5; j += i) {
            c += 2;
            dp[j] = min(dp[j], dp[i] + c);
        }
    }
}

int main() {
    int ts = 1;
    cin >> ts;
    vector<int> X;
    int mx = 0;
    for (int t = 1; t <= ts; t++) {
        int l;
        cin >> l;
        X.push_back(l);
        mx = max(mx, l);
    }
    solve(mx);
    for (int t = 0; t < ts; t++) {
        cout << "Case #" << t + 1 << ": " << dp[X[t]] << endl;
    }
    return 0;
}


