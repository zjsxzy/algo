#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string res, temp;
    for (int i = 0; i < n; i++) {
        if (s[i] == '\"') {
            if (temp.size() > 0) {
                temp += s[i];
                res += temp;
                temp = "";
            } else {
                temp += s[i];
            }
        } else {
            if (temp.size() > 0) {
                temp += s[i];
            } else {
                if (s[i] == ',') res += '.';
                else res += s[i];
            }
        }
    }
    cout << res << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}