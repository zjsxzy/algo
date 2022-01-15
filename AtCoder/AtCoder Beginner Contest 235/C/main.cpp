#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    map<int, int> curr;
    map<int, vector<int>> occur;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        curr[a[i]]++;
        occur[a[i]].push_back(i + 1);
    }
    while (q--) {
        int x, k;
        cin >> x >> k;
        if (curr.find(x) == curr.end()) {
            cout << -1 << endl;
        } else {
            if (k > occur[x].size()) {
                cout << -1 << endl;
            } else {
                cout << occur[x][k - 1] << endl;
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

