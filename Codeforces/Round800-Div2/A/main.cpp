#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int a, b;
    cin >> a >> b;
    string s;
    if (a < b) {
        for (int i = 0; i < a; i++) {
            s += '1';
            s += '0';
        }
        for (int i = 0; i < b - a; i++) {
            s += '1';
        }
    } else {
        for (int i = 0; i < b; i++) {
            s += '0';
            s += '1';
        }
        for (int i = 0; i < a - b; i++) {
            s += '0';
        }
    }
    cout << s << endl;
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

