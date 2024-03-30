#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<LL> x(Q + 1), t(Q + 1);
    set<LL> st;
    map<int, vector<int>> vec;
    for (int i = 1; i <= Q; i++) {
        cin >> x[i];
        vec[x[i]].push_back(i);
        if (st.count(x[i])) st.erase(x[i]);
        else st.insert(x[i]);
        t[i] = (int)st.size();
    }
    for (int i = 1; i <= Q; i++) {
        t[i] += t[i - 1];
    }
    vector<LL> res(N + 1);
    for (auto& [k, v]: vec) {
        int sz = v.size();
        for (int i = 0; i < sz; i += 2) {
            if (i + 1 < sz) res[k] += t[v[i + 1] - 1] - t[v[i] - 1];
            else res[k] += t[Q] - t[v[i] - 1];
        }
    }
    for (int i = 1; i <= N; i++) cout << res[i] << ' ';
    cout << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}