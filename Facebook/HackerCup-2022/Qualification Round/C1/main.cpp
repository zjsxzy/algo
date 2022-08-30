#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i < n; i++) {
        int sz = s.size();
        if (s[sz - 1] == '.') s[sz - 1] = '-';
        else s[sz - 1] = '.';
        if (i & 1) s += '.';
        else s += '-';
        cout << s << endl;
    }
}

int main() {
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       cout << "Case #" << t << ": " << endl;;
       solve();
   }
   return 0;
}

