#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    bool flag = false;
    while (n--) {
        string s;
        cin >> s;
        if (s == "and" || s == "not" || s == "that" || s == "the" || s == "you") flag = true;
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
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