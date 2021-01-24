#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    string s, t;
    cin >> s >> t;
    int p = 0, res = 1;
    for (int i = 0; i < t.size(); i++) {
        bool flag = false;
        while (p < s.size()) {
            if (t[i] == s[p]) {
                flag = true;
            }
            p++;
            if (flag) break;
        }
        if (p == s.size()) {
            res++;
            p = 0;
        }
        if (!flag) {
            while (p < s.size()) {
                if (t[i] == s[p]) {
                    p++;
                    break;
                }
                p++;
            }
        }
        //cout << i << " " << res << endl;
    }
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}

