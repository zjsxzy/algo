#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> one(n + 1), q(n + 1);
    for (int i = 0; i < n; i++) {
        one[i + 1] = one[i] + (s[i] == '1');
        q[i + 1] = q[i] + (s[i] == '?');
    }
    int res = 0;
    for (int i = 1; i + k - 1 <= n; i++) {
        int j = i + k - 1;
        if (one[j] - one[i - 1] == one[n] && one[j] - one[i - 1] + q[j] - q[i - 1] == k) {
            res++;
        }
    }
    if (res == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
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

