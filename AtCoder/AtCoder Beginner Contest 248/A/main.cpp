#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    vector<int> b(10);
    for (auto c: s) {
        b[c - '0'] = 1;
    }
    for (int i = 0; i < 10; i++) {
        if (b[i] == 0) {
            cout << i << endl;
            return;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

