#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        v.push_back({l, 0});
        v.push_back({r, 1});
    }
    sort(v.begin(), v.end());
    set<pair<int, int>> ans;
    int curr = 0, left;
    for (auto p: v) {
        if (p.second == 0) {
            if (curr == 0) left = p.first;
            curr++;
        } else {
            curr--;
            if (curr == 0) ans.insert({left, p.first});
        }
    }
    for (auto x: ans) {
        cout << x.first << ' ' << x.second << endl;
    }
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

