#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int k;
    cin >> k;
    if (k < 60) {
        printf("21:%02d\n", (k));
    } else {
        printf("22:%02d\n", (k - 60));
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

