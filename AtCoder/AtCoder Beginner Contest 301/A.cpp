#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int t = 0, a = 0;
    for (auto c: s) {
        if (c == 'T') t++;
        else a++;
    }
    if (t > a) cout << "T" << endl;
    else if (a > t) cout << "A" << endl;
    else {
        int ans = t;
        t = 0, a = 0;
        for (auto c: s) {
            if (c == 'T') t++;
            else a++;
            if (t == ans) {
                cout << "T" << endl;
                return;
            }
            if (a == ans) {
                cout << "A" << endl;
                return;
            }
        }
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