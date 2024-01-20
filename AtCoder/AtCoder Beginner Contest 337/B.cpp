#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    char ch = '#';
    string v;
    for (auto c: s) {
        if (c != ch) v.push_back(c);
        ch = c;
    }
    set<string> st;
    st.insert("");
    st.insert("A"); st.insert("B"); st.insert("C");
    st.insert("AB"); st.insert("BC"); st.insert("AC");
    st.insert("ABC");
    if (st.find(v) == st.end()) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
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