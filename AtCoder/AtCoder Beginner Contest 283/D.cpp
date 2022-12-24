#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<char> st;
    set<char> box;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push_back(s[i]);
        } else if (s[i] == ')') {
            while (st.back() != '(') {
                box.erase(st.back());
                st.pop_back();
            }
            st.pop_back();
        } else {
            if (box.count(s[i])) {
                cout << "No" << endl;
                return;
            }
            box.insert(s[i]);
            st.push_back(s[i]);
        }
    }
    cout << "Yes" << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}