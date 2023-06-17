#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> p(n + 1);
    for (int i = 1; i <= n * 3; i++) {
        int x;
        cin >> x;
        p[x].push_back(i);
    }
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i].first = p[i][1];
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++) {
        cout << a[i].second << ' ';
    }
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