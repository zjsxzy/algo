#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    LL k;
    cin >> n >> k;
    vector<LL> a(n);
    set<pair<LL, int>> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 0) {
            st.insert({a[i], i});
        }
    }
    LL circle = 0;
    while (k > 0 && !st.empty() && (int)st.size() <= k) {
        LL c = k / (LL)st.size();
        auto p = st.begin();
        LL x = p->first;
        int i = p->second;
        if (x - circle <= c) {
            k -= (x - circle) * (LL)st.size();
            circle = x;
            st.erase({x, i});
        } else {
            circle += c;
            k -= c * (LL)st.size();
        }
    }
    if (k > 0 && (int)st.size() > k) {
        vector<int> idx;
        for (auto [x, i]: st) {
            idx.push_back(i);
        }
        sort(idx.begin(), idx.end());
        for (int i = 0; i < k; i++) a[idx[i]]--;
    }
    for (int i = 0; i < n; i++) cout << max(0ll, a[i] - circle) << ' ';
    cout << endl;
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

