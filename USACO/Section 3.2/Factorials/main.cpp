/*
ID: frankzh1
TASK: fact4
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    int res = 1;
    for (int i = 2; i <= n; i++) {
        res = res * i;
        while (res % 10 == 0) {
            res /= 10;
        }
        res %= 10000;
    }
    cout << res % 10 << endl;
}

int main() {
    freopen("fact4.in", "r", stdin);
    freopen("fact4.out", "w", stdout);
    solve();
    return 0;
}

