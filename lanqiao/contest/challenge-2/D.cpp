#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, P;
    cin >> n >> P;
    vector<int> s(n + 1), k(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) {
        int f;
        cin >> f >> s[i] >> k[i];
        g[f].push_back(i);
    }
    set<pair<int, int>> pq;
    pq.insert({k[1], 1});
    LL sum = P;
    int res = 0;
    while (!pq.empty()) {
        auto x = pq.begin();
        int ku = x->first, u = x->second;
        pq.erase(pq.begin());
        if (sum >= ku) {
            res++;
            sum += s[u];
            for (auto v: g[u]) {
                pq.insert({k[v], v});
            }
        }
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