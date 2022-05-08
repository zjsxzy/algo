#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void add(set<int>& st, set<int>& common, int val) {
    if (st.find(val) != st.end()) return;
    if (common.find(val) == common.end()) {
        common.insert(val);
    } else {
        common.erase(val);
    }
    st.insert(val);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& x: a) cin >> x;
    for (auto& x: b) cin >> x;

    set<int> sta, stb, stc;
    vector<int> l(n, n), r(n, -1);
    for (int i = 0, j = 0; i < n; i++) {
        add(sta, stc, a[i]);
        while (j < n && (int) stb.size() < (int) sta.size()) {
            add(stb, stc, b[j]);
            j++;
        }
        if ((int) sta.size() == (int) stb.size() && (int) stc.size() == 0) {
            l[i] = j - 1;
        }
    }
    sta.clear();
    stb.clear();
    stc.clear();
    for (int i = 0, j = 0; i < n; i++) {
        add(sta, stc, a[i]);
        while (j < n && (int) stb.size() <= (int) sta.size()) {
            if (stb.find(b[j]) == stb.end()) {
                if ((int) stb.size() == (int) sta.size()) break;
                add(stb, stc, b[j]);
            }
            j++;
        }
        if ((int) sta.size() == (int) stb.size() && (int) stc.size() == 0) {
            r[i] = j - 1;
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if (l[x] <= y && y <= r[x]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

