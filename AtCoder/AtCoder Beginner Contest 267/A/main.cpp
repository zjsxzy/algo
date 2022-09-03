#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    if (s == "Monday") cout << 5 << endl;
    else if (s == "Tuesday") cout << 4 << endl;
    else if (s == "Wednesday") cout << 3 << endl;
    else if (s == "Thursday") cout << 2 << endl;
    else cout << 1 << endl;
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

