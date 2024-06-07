#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> left(n + 1), right(n + 1);
    for (int i = 1; i <= n; i++) {
        left[i] = i - 1;
        while (left[i] >= 1 && a[left[i]] >= a[i]) {
            left[i] = left[left[i]];
        }
    }
    for (int i = n; i >= 1; i--) {
        right[i] = i + 1;
        while (right[i] <= n && a[right[i]] >= a[i]) {
            right[i] = right[right[i]];
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << i << ' ' << a[i] << ' ' << right[i] - left[i] - 1 << endl;
    // }
    vector<pair<int, pair<int, pair<int, int>>>> vec;
    int q;
    cin >> q;
    for (int i = 1; i <= n; i++) {
        vec.push_back({a[i], {q, {right[i] - left[i] - 1, -1}}});
    }
    for (int i = 0; i < q; i++) {
        int v, minl, maxl;
        cin >> v >> minl >> maxl;
        vec.push_back({v, {i, {minl, maxl}}});
    }
    sort(vec.rbegin(), vec.rend());
    set<int> st;
    vector<int> ans(q);
    for (auto v: vec) {
        int val = v.first, idx = v.second.first;
        int l = v.second.second.first, r = v.second.second.second;
        // cout << val << ' ' << idx << ' ' << l << ' ' << r << endl;
        if (idx == q) {
            st.insert(l);
        } else {
            auto x = st.lower_bound(l);
            if (x != st.end()) {
                ans[idx] = 1;
            }
        }
    }
    for (auto x: ans) {
        cout << (x == 1 ? "Yes" : "No") << endl;
    }
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