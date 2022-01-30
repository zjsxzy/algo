#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

bool palindrome(string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) return false;
    }
    return true;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int i = n - 1, j = 0;
    int prefix = 0, suffix = 0;
    while (s[i] == 'a') i--, suffix++;
    while (s[j] == 'a') j++, prefix++;
    if (prefix > suffix) {
        cout << "No" << endl;
        return;
    }
    if (palindrome(s.substr(j, i - j + 1))) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

