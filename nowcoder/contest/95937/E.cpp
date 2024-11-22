#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int idx = 0;
    vector<int> stk, ans(n);
    for (auto c: s) {
        if (c == '(') {
            stk.push_back(idx);
            idx++;
        } else {
            if (stk.empty()) {
                cout << -1 << endl;
                return;
            }
            int u = stk.back();
            stk.pop_back();
            ans[u] = n - stk.size() - 1;
        }
    }
    if (!stk.empty()) {
        cout << -1 << endl;
        return;
    }
    for (auto x: ans) cout << x << ' ';
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