#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    int a = n / 100, b = n / 10 % 10, c = n % 10;
    int x = b * 100 + c * 10 + a;
    int y = c * 100 + a * 10 + b;
    cout << n + x + y << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

