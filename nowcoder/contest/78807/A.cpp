#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    vector<string> s(6);
    for (int i = 0; i < 6; i++) cin >> s[i];
    if (s[0][3] == '.') {
        cout << 'o' << endl;
    } else {
        if (s[5][3] == '.') cout << 'm' << endl;
        else cout << 'p' << endl;
    }
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