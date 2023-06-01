#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    char c;
    cin >> c;
    int n;
    cin >> n;
    string s;
    for (int i = 1; i <= n; i++) {
        s += '\n';
        for (int j = 1; j <= i; j++) {
            s += to_string(j) + "*" + to_string(i) + "=" + to_string(i * j) + ",";
        }
    }
    int res = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (c == s[i]) res++;
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