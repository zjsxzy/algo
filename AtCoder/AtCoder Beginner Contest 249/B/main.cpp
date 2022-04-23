#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    bool up = false, low = false, distinct = true;
    set<char> st;
    for (auto c: s) {
        if (c >= 'a' && c <= 'z') low = true;
        if (c >= 'A' && c <= 'Z') up = true;
        if (st.find(c) != st.end()) {
            distinct = false;
        }
        st.insert(c);
    }
    if (up && low && distinct) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

