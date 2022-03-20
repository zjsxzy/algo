#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

void solve() {
    int n;
    string t;
    cin >> n >> t;
    int x = 0, y = 0, d = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] == 'S') {
            x += dx[d];
            y += dy[d];
        } else {
            d = (d + 1) % 4;
        }
    }
    cout << x << " " << y << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

