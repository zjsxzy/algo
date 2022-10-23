#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char> q;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'Q') q.push_back('Q');
        else {
            if (!q.empty()) {
                q.pop_back();
            }
        }
    }
    if (q.size()) cout << "No" << endl;
    else cout << "Yes" << endl;
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

