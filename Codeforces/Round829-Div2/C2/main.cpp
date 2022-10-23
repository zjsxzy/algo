#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), vec;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != 0) vec.push_back(i);
    }
    if ((int)vec.size() & 1) {
        cout << -1 << endl;
        return;
    }
    vector<pair<int, int>> ans;
    int last = -1;
    for (int i = 0; i < (int)vec.size(); i += 2) {
        if (vec[i] != last + 1) {
            ans.push_back({last + 1, vec[i] - 1});
        }
        int x = a[vec[i]], y = a[vec[i + 1]];
        if ((vec[i + 1] - vec[i]) % 2 == 0) y = -y;
        if (x == y) {
            ans.push_back({vec[i], vec[i + 1]});
        } else {
            ans.push_back({vec[i], vec[i]});
            ans.push_back({vec[i] + 1, vec[i + 1]});
        }
        last = vec[i + 1];
    }
    if (last != n - 1) ans.push_back({last + 1, n - 1});
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

