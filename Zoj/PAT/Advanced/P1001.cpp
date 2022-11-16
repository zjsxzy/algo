#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int a, b;
    cin >> a >> b;
    string res;
    if (a + b < 0) res = to_string(- a - b);
    else res = to_string(a + b);
    reverse(res.begin(), res.end());
    string output;
    for (int i = 0; i < (int)res.size(); i++) {
        output += res[i];
        if (i % 3 == 2 && i != (int)res.size() - 1) output += ',';
    }
    reverse(output.begin(), output.end());
    if (a + b < 0) cout << '-';
    cout << output << endl;
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

