#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n & 1) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i + 1 < n; i += 2) {
        if (a[i] == a[i + 1]) ans.push_back({i, i + 1});
        else {
            ans.push_back({i, i});
            ans.push_back({i + 1, i + 1});
        }
    }
    cout << (int)ans.size() << endl;
    for (auto p: ans) cout << p.first + 1 << ' ' << p.second + 1 << endl;
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

