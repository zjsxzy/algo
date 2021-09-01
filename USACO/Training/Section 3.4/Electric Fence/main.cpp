/*
ID: frankzh1
TASK: fence9
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    int n, m, p;
    cin >> n >> m >> p;
    int x = gcd(n, m) + gcd(abs(p - n), m) + p;
    int s = (p * m) / 2;
    int res = s - x / 2 + 1;
    cout << res << endl;
}

int main() {
    freopen("fence9.in", "r", stdin);
    freopen("fence9.out", "w", stdout);
    solve();
    return 0;
}

