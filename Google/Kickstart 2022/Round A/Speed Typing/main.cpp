#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve(int cs) {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int j = 0;
    printf("Case #%d: ", cs);
    for (int i = 0; i < n; i++) {
        if (s[i] == t[j]) j++;
        else {
            while (s[i] != t[j] && j < m) {
                j++;
            }
            if (j == m) {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }
    cout << m - n << endl;
}

int main() {
    int ts;
    cin >> ts;
    for (int cs = 1; cs <= ts; cs++) {
        solve(cs);
    }
    return 0;
}

