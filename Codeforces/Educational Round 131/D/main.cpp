#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        l[i] = i / (b[i] + 1) + 1;
        if (b[i] == 0) r[i] = n;
        else r[i] = i / b[i];
    }
    vector<pair<int, int>> vec;
    for (int i = 1; i <= n; i++) {
        vec.push_back({i, n + 1});
    }
    for (int i = 1; i <= n; i++) {
        vec.push_back({l[i], i});
    }
    sort(vec.begin(), vec.end());
    set<pair<int, int>> st;
    for (auto& v: vec) {
        if (v.second == n + 1) {
            auto x = st.begin();
            a[x->second] = v.first;
            st.erase(x);
        } else {
            int id = v.second;
            st.insert({r[id], id});
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
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

