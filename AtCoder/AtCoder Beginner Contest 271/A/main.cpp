#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int x;
    cin >> x;
    cout << std::uppercase << std::hex << setfill('0') << setw(2) << x << endl;
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

