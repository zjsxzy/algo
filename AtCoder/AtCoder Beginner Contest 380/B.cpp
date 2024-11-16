#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    vector<int> ans;
    int cnt = -1;
    for (auto c: s) {
        if (c == '|') {
            if (cnt != -1) ans.push_back(cnt);
            cnt = 0;
        } else cnt++;
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