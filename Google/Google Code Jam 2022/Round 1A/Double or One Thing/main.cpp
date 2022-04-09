#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    string t;
    int n = s.size();
    char c = s[0];
    int num = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] != c) {
            if (c < s[i]) {
                for (int j = 0; j < num * 2; j++) {
                    t += c;
                }
            } else {
                for (int j = 0; j < num; j++) {
                    t += c;
                }
            }
            c = s[i];
            num = 1;
        } else {
            num++;
        }
    }
    for (int i = 0; i < num; i++) t += c;
    cout << t << endl;
}

int main() {
    int ts;
    cin >> ts;
    for (int cs = 1; cs <= ts; cs++) {
        printf("Case #%d: ", cs);
        solve();
    }
    return 0;
}

