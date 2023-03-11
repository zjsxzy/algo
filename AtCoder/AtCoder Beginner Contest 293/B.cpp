#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> called(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        if (!called[i]) {
            called[a[i]] = 1;
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) if (!called[i]) ans.push_back(i);
    cout << (int)ans.size() << endl;
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