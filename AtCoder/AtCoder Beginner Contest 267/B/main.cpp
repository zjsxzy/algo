#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    s = ' ' + s;
    if (s[1] == '1') {
        cout << "No" << endl;
        return;
    }
    vector<vector<int>> col(7);
    col[0].push_back(7);
    col[1].push_back(4);
    col[2].push_back(2); col[2].push_back(8);
    col[3].push_back(1); col[3].push_back(5);
    col[4].push_back(3); col[4].push_back(9);
    col[5].push_back(6);
    col[6].push_back(10);
    int n = 7;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                bool fi = false;
                for (auto x: col[i]) if (s[x] == '1') fi = true;
                bool fk = false;
                for (auto x: col[k]) if (s[x] == '1') fk = true;
                bool fj = true;
                for (auto x: col[j]) if (s[x] == '1') fj = false;
                if (fi && fj && fk) {
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
    }
    cout << "No" << endl;
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

