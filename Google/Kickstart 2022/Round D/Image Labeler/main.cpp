#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    sort(a.begin(), a.end());
    double res = 0;
    while (m > 1) {
        res += a.back();
        a.pop_back();
        m--;
    }
    n = a.size();
    if (n & 1) {
        res += a[n / 2];
    } else {
        res += 1. * (a[n / 2 - 1] + a[n / 2]) * 0.5;
    }
    printf("%.1f\n", res);
}

int main() {
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       cout << "Case #" << t << ": ";
       solve();
   }
   return 0;
}

