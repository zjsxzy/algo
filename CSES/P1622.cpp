#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    set<string> st;
    do {
        st.insert(s);
    } while (next_permutation(s.begin(), s.end()));
    cout << (int)st.size() << endl;
    for (auto x: st) cout << x << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}