#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

char f(char c) {
    if (islower(c)) return toupper(c);
    return tolower(c);
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int q;
    cin >> q;
    while (q--) {
        LL k;
        cin >> k;
        k--;
        char c = s[k % n];
        LL b = k / n;
        if (__builtin_popcountll(b) % 2) cout << f(c) << ' ';
        else cout << c << ' ';
    }
    cout << endl;
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