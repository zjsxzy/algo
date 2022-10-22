#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int base = 10000;
int dp[1005][20005];

bool check(vector<int>& a, int target) {
    /*
    for (auto x: a) cout << x << ' ';
    cout << target << endl;
    */
    memset(dp, 0, sizeof(dp));
    int n = a.size();
    dp[0][base] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 20000; j++) {
            if (dp[i][j]) {
                if (j + a[i] >= 0 && j + a[i] <= 20000) {
                    dp[i + 1][j + a[i]] |= dp[i][j];
                }
                if (j - a[i] >= 0 && j - a[i] <= 20000) {
                    dp[i + 1][j - a[i]] |= dp[i][j];
                }
            }
        }
    }
    return dp[n][base + target];
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> A(n);
    for (auto& x: A) cin >> x;
    vector<int> vec;
    for (int i = 1; i < n; i += 2) vec.push_back(A[i]);
    bool f = check(vec, y);
    vec.clear();
    for (int i = 2; i < n; i += 2) vec.push_back(A[i]);
    bool g = check(vec, x - A[0]);
    if (f & g) cout << "Yes" << endl;
    else cout << "No" << endl;
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

