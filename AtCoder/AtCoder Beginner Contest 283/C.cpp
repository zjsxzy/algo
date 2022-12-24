#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    int n = s.size(), res = 0;
    for (int i = n - 1; i >= 0; ) {
        if (i - 1 >= 0 && s.substr(i - 1, 2) == "00") {
            i -= 2;
        } else {
            i--;
        }
        res++;
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