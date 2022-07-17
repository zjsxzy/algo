#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<int> a(n), b(n), vst(n);
    for (auto& x: a) cin >> x;
    for (auto& x: b) cin >> x;

    vector<pair<int, int>> vec;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        vec.push_back({-a[i], i});
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < x; i++) {
        ans.push_back(vec[i].second);
        vst[vec[i].second] = true;
    }

    vec.clear();
    for (int i = 0; i < n; i++) {
        if (vst[i]) continue;
        vec.push_back({-b[i], i});
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < y; i++) {
        ans.push_back(vec[i].second);
        vst[vec[i].second] = true;
    }

    vec.clear();
    for (int i = 0; i < n; i++) {
        if (vst[i]) continue;
        int t = a[i] + b[i];
        vec.push_back({-t, i});
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < z; i++) {
        ans.push_back(vec[i].second);
    }

    sort(ans.begin(), ans.end());
    for (auto i: ans) {
        cout << i + 1 << endl;
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

