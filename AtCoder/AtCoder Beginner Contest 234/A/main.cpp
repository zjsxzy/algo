#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

int f(int t) {
    return t * t + 2 * t + 3;
}

void solve() {
    int t;
    cin >> t;
    cout << f(f(f(t) + t) + f(f(t))) << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

