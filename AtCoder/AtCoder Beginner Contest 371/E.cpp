#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (!mp.count(x)) mp[x].push_back(0);
        mp[x].push_back(i); 
    }
    auto calc = [&](vector<int>& vec) {
        LL ans = (LL)n * (n + 1) / 2;
        vec.push_back(n + 1);
        for (int i = 1; i < vec.size(); i++) {
            LL t = vec[i] - vec[i - 1] - 1;
            ans -= (LL)t * (t + 1) / 2;
        }
        return ans;
    };
    LL res = 0;
    for (auto& [k, v]: mp) {
        res += calc(v);
    }
    cout << res << '\n';
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