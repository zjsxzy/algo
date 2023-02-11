#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int x;
    cin >> x;
    vector<int> vst(x + 1, 0);
    for (int i = 0; i < m; i++) vst[b[i]] = -1;
    vst[0] = 1;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int i = 0; i < n; i++) {
            if (curr + a[i] <= x && vst[curr + a[i]] == 0) {
                vst[curr + a[i]] = 1;
                q.push(curr + a[i]);
            }
        }
    }
    if (vst[x] == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
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