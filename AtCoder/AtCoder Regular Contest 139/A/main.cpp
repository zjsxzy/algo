#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> t(n);
    for (auto& x: t) {
        cin >> x;
    }
    LL curr = 0;
    for (int i = 0; i < n; i++) {
        LL x = (1LL << t[i]);
        bool flag = false;
        for (int j = t[i]; j <= 60; j++) {
            if ((curr & (1LL << j)) == 0) {
                if (!flag) {
                    x |= (1LL << j);
                    flag = true;
                }
            } else {
                if (flag) x |= (1LL << j);
            }
        }
        curr = x;
    }
    cout << curr << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

