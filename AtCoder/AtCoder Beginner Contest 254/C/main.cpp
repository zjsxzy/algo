#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[i % k].push_back(a[i]);
    }
    for (int i = 0; i < k; i++) {
        sort(mp[i].begin(), mp[i].end());
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = mp[i % k][i / k];
    }
    if (is_sorted(b.begin(), b.end())) cout << "Yes" << endl;
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

