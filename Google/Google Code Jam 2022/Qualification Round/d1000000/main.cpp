#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> die(n);
    int mx = 0;
    for (auto& x: die) {
        cin >> x;
        mx = max(mx, x);
    }
    vector<int> mem(mx + 1);
    for (auto& x: die) {
        mem[x]++;
    }
    int res = 0, left = 0;
    for (int i = mx; i > 0; i--) {
        left += mem[i];
        if (left > 0) {
            left--;
            res++;
        }
    }
    cout << res << endl;
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

