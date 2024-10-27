#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m, k;
    cin >> n >> m;
    vector<int> pat(n);
    auto str2int = [&](string s) {
        int res = 0;
        for (int i = 0; i < m; i++) {
            if (s[i] == '1') res += (1 << i);
        }
        return res;
    };
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        pat[i] = str2int(s);
    }
    cin >> k;
    vector<int> med;
    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        int t = str2int(s);
        if (t > 0) med.push_back(t);
    }
    k = med.size();
    vector<pair<int, int>> st;
    for (int i = 1; i < (1 << k); i++) {
        int curr = 0, cnt = 0;
        for (int j = 0; j < k; j++) {
            if (i >> j & 1) {
                cnt++;
                curr |= med[j];
            }
        }
        st.push_back({cnt, curr});
    }
    sort(st.begin(), st.end());
    st.resize(unique(st.begin(), st.end()) - st.begin());
    for (int i = 0; i < n; i++) {
        int target = pat[i], res = k + 1;
        if (target == 0) {
            cout << 0 << endl;
            continue;
        }
        for (auto [c, v]: st) {
            int x = target ^ v & target;
            if (x == 0) {
                res = c;
                break;
            }
        }
        if (res == k + 1) cout << -1 << endl;
        else cout << res << endl;
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