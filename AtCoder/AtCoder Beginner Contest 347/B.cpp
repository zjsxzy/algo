#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    set<string> st;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            st.insert(s.substr(i, j - i + 1));
        }
    }
    cout << (int)st.size() << endl;
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