#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    vector<string> res(n);
    for (int i = 0; i < n; i++) res[i] = grid[i];
    for (int j = 0; j < m; j++) {
        string s;
        for (int i = 0; i < n; i++) s += grid[i][j];

        //cout << s << endl;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '*') {
                int k = i;
                while (k < n - 1 && s[k + 1] == '.') {
                    swap(s[k], s[k + 1]);
                    k++;
                }
            }
        }
        //cout << s << endl;
        //cout << endl;

        for (int i = 0; i < n; i++) res[i][j] = s[i];
    }
    for (int i = 0; i < n; i++) cout << res[i] << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

