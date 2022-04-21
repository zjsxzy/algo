#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

int first[26][26];
int second[26][26];

void solve() {
    int n;
    cin >> n;
    memset(first, 0, sizeof(first));
    memset(second, 0, sizeof(second));
    LL res = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int i = 0; i < 26; i++) {
            if (s[1] - 'a' == i) continue;
            res += first[s[0] - 'a'][i];
        }
        for (int i = 0; i < 26; i++) {
            if (s[0] - 'a' == i) continue;
            res += second[s[1] - 'a'][i];
        }

        first[s[0] - 'a'][s[1] - 'a']++;
        second[s[1] - 'a'][s[0] - 'a']++;
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

