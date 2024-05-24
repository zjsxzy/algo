#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    map<int, int> mp;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int x = i * 3 + j + 1;
            int a;
            cin >> a;
            mp[x] = a;
        }
    }
    string s;
    cin >> s;
    for (auto c: s) cout << mp[c - '0'];
    cout << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}