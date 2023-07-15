#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    vector<set<int>> c(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            c[i].insert(x);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (p[i] < p[j]) continue;
            bool flag = true;
            for (auto x: c[i]) {
                if (c[j].find(x) == c[j].end()) {
                    flag = false;
                    break;
                }
            }
            int cnt = 0;
            for (auto x: c[j]) {
                if (c[i].find(x) == c[i].end()) cnt++;
            }
            if (!flag) continue;
            if (cnt == 0 && p[i] == p[j]) continue;
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
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