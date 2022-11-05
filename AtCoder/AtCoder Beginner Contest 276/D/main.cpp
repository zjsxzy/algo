#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), two(n), three(n);
    int mtwo = 1e9, mthree = 1e9;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        while (a[i] % 2 == 0) {
            a[i] /= 2;
            two[i]++;
        }
        mtwo = min(mtwo, two[i]);
        while (a[i] % 3 == 0) {
            a[i] /= 3;
            three[i]++;
        }
        mthree = min(mthree, three[i]);
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            cout << -1 << endl;
            return;
        }
    }
    LL res = 0;
    for (int i = 0; i < n; i++) {
        res += two[i] - mtwo;
        res += three[i] - mthree;
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

