#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    LL k;
    cin >> n >> k;
    vector<LL> a(n), s(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) s[i] = a[i];
        else s[i] = s[i - 1] + a[i];
    }
    LL res = s[n - 1] - k * n;
    for (int i = n - 1; i >= 0; i--) {
        LL good_sum = 0, bad_sum = 0;
        if (i > 0) good_sum = s[i - 1] - k * i;
        for (int j = 0; j < 32; j++) {
            if (i + j < n) {
                bad_sum += a[i + j] >> (j + 1);
            }
        }
        res = max(res, good_sum + bad_sum);
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

