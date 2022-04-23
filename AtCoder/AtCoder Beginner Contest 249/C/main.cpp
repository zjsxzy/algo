#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int res = 0;
    for (int i = 1; i < (1 << n); i++) {
        set<char> alpha;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                for (auto c: s[j]) alpha.insert(c);
            }
        }
        int sum = 0;
        for (auto c: alpha) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    if (s[j].find(c) != string::npos) cnt++;
                }
            }
            if (cnt == k) sum++;
        }
        res = max(res, sum);
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

