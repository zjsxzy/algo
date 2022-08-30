#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int r, c;
    cin >> r >> c;
    vector<string> s(r);
    vector<pair<int, int>> tree;
    for (int i = 0; i < r; i++) {
        cin >> s[i];
        for (int j = 0; j < c; j++) {
            if (s[i][j] == '^') tree.push_back({i, j});
        }
    }
    if ((int)tree.size() == 0) {
        cout << "Possible" << endl;
        for (int i = 0; i < r; i++) cout << s[i] << endl;
        return;
    }

    if (r == 1 || c == 1) {
        cout << "Impossible" << endl;
        return;
    }
    cout << "Possible" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cout << '^';
        cout << endl;
    }
}

int main() {
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       cout << "Case #" << t << ": ";
       solve();
   }
   return 0;
}

