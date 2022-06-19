#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    int st = 1, ed = n;
    for (int i = 0; i < n; i++) {
        vector<int> a(n);
        int l = st, r = ed;
        for (int j = 0; j < n; j++) {
            if (j & 1) {
                a[j] = l++;
            } else {
                a[j] = r--;
            }
            cout << a[j] << ' ';
        }
        cout << endl;
        st += n;
        ed += n;
    }
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

