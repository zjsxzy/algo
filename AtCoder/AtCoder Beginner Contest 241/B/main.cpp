#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    vector<int> flag(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        bool find = false;
        cin >> b[i];
        for (int j = 0; j < n; j++) {
            if (a[j] == b[i] && !flag[j]) {
                flag[j] = true;
                find = true;
                break;
            }
        }
        if (!find) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

