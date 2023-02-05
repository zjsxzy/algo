#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s, t;
    cin >> s >> t;
    map<int, set<int>> g;
    auto idx = [&](char c) {
        if (c >= 'a' && c <= 'z') return c - 'a';
        return 26 + c - 'A';
    };
    set<int> st;
    for (int i = 0; i < 52; i++) st.insert(i);
    int n = s.size();
    for (int i = 0; i < n; i++) {
        g[idx(s[i])].insert(idx(t[i]));
        st.erase(idx(t[i]));
    }
    int res = 0;
    vector<int> deg(52);
    for (auto [k, v]: g) {
        if (v.size() > 1) {
            cout << -1 << endl;
            return;
        }
        if (v.size() == 1) {
            if (k != *v.begin()) {
                res++;
                deg[*v.begin()]++;
            }
        }
    }
    queue<int> q;
    vector<bool> vst(52, true);
    for (int i = 0; i < 52; i++) {
        if (deg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (g[u].size() == 0) continue;
        int v = *g[u].begin();
        if (u == v) continue;
        vst[v] = false;
        deg[v]--;
        if (deg[v] == 0) q.push(v);
    }
    // count cycles
    for (int i = 0; i < 52; i++) {
        if (deg[i] == 0) continue;
        bool flag = vst[i];
        int u = *g[i].begin(), cnt = 1;
        if (u == i) continue; // self cycle
        // cout << i << ' ' << c << ' ' << u << ' ' << (char)*g[c].begin() << endl;
        deg[i] = 0;
        while (u != i) {
            flag &= vst[u];
            deg[u] = 0;
            cnt++;
            u = *g[u].begin();
        }
        if (flag) {
            if (cnt == 52 || st.empty()) {
                cout << -1 << endl;
                return;
            }
            // st.erase(st.begin());
            res++;
        }
    }
    cout << res << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}