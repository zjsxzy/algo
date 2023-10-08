#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int i = 0, j = n - 1;
    while (true) {
        while (i < j && s[i] == s[j]) {
            i++;
            j--;
        }
        bool f1 = true, f2 = true;
        while (i < j && s[i] == s[i + 1]) {
            i += 2;
            f1 = false;
        }
        while (i < j && s[j] == s[j - 1]) {
            j -= 2;
            f2 = false;
        }
        if (f1 && f2) break;
    }
    string t = s.substr(i, j - i + 1);
    vector<char> st;
    for (auto c: t) {
        st.push_back(c);
        while (st.size() > 2 && st.back() == st[st.size() - 2]) {
            st.pop_back();
            st.pop_back();
        }
    }
    std::cout << n - st.size() << endl;
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