#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    string res = "";
    int cnt = 0;
    for (auto c: s) {
        if (c == '|') {
            cnt++; 
            continue;
        }
        if (cnt == 0 || cnt == 2) res += c;
    }
    cout << res << endl;
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