#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<pair<int, int>> vec;
    string t = "bessie";
    int p = 0;
    vector<pair<int, char>> stk;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'b' || s[i] == 'e' || s[i] == 'i' || s[i] == 's') {
            stk.push_back({i, s[i]});
            if (s[i] == t[p]) p++; 
            if (p == (int)t.size()) {
                int r = stk.back().first, l;
                while (p) {
                    if (stk.back().second == t[p - 1]) {
                        p--;
                    }
                    if (p == 0) l = stk.back().first;
                    stk.pop_back();
                }
                vec.push_back({l, r});
                stk.clear();
            }
        }
    }
    // for (auto [l, r]: vec) cout << l << ' ' << r << endl;
    LL res = 0;
    int m = vec.size(), prev = -1;
    for (int i = 0; i < m; i++) {
        LL l = vec[i].first - prev;
        LL curr = 1;
        for (int j = i + 1; j < m; j++) {
            res += curr * l * (vec[j].second - vec[j - 1].second);
            curr++;
        }
        res += curr * l * (n - vec[m - 1].second);
        prev = vec[i].first;
    }
    cout << res << endl;
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