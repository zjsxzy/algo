#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int x = 0, y = 0;
    set<pair<int, int>> st;
    st.insert({x, y});
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (auto c: s) {
        if (c == 'R') {
            x++;
        } else if (c == 'L') {
            x--;
        } else if (c == 'U') {
            y++;
        } else if (c == 'D') {
            y--;
        }
        if (st.find({x, y}) != st.end()) {
            // cout << c << ' ' << x << ' ' << y << endl;
            cout << "Yes" << endl;
            return;
        }
        st.insert({x, y});
    }
    cout << "No" << endl;
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