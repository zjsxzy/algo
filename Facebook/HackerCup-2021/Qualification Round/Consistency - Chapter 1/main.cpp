#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

int is_vowel(char c) {
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return 1;
    return -1;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size(), res = INT_MAX;
    for (int c = 0; c < 26; c++) {
        string t(n, 'A' + c);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                if (is_vowel(s[i]) * is_vowel(t[i]) == 1) {
                    sum += 2;
                } else {
                    sum++;
                }
            }
        }
        if (sum < res) res = sum;
    }
    cout << res << endl;
}

int main() {
    int ts;
    cin >> ts;
    for (int cas = 1; cas <= ts; cas++) {
        printf("Case #%d: ", cas);
        solve();
    }
    return 0;
}

