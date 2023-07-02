#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    std::cin >> n;
    string p;
    for (int j = 0; j < n; j++) p += '*';
    for (int i = 0; i < 4 * n - n; i++) {
        std::cout << p;
        for (int j = 0; j < 2 * n; j++) std::cout << '.';
        std::cout << p << endl;
    }
    for (int i = 0; i < n; i++) {
        string s;
        for (int j = 0; j < i + 1; j++) s += '.';
        s += p;
        for (int j = 0; j < n - (i + 1); j++) s += '.';
        std::cout << s;
        reverse(s.begin(), s.end());
        std::cout << s << endl;
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