#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL a, b, C, D;
    cin >> a >> b >> C >> D;
    vector<LL> c(4);
    for (auto& x: c) cin >> x;
    LL res1 = 0;
    if (c[0] <= c[1]) {
        LL t = min(a, C);
        res1 += t * c[0]; // a->c
        res1 += (a - t) * c[1]; // a->b
        res1 += (C - t) * c[2]; // b->c
        res1 += (b - (C - t)) * c[3]; // b->d
    } else {
        LL t = min(a, D);
        res1 += (a - t) * c[0];
        res1 += t * c[1];
        res1 += (b - (D - t)) * c[2];
        res1 += (D - t) * c[3];
    }
    LL res2 = 0;
    if (c[2] <= c[3]) {
        LL t = min(b, C);
        res2 += t * c[2];
        res2 += (b - t) * c[3];
        res2 += (C - t) * c[0];
        res2 += (a - (C - t)) * c[1];
    } else {
        LL t = min(b, D);
        res2 += (b - t) * c[2];
        res2 += t * c[3];
        res2 += (C - (b - t)) * c[0];
        res2 += (D - t) * c[1];
    }
    cout << min(res1, res2) << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

