#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    long long res = 0, curr = 1;
    for (int i = 0; i < n; i++) {
        res += (s.back() - 'A' + 1) * curr;
        s.pop_back();
        curr *= 26;
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