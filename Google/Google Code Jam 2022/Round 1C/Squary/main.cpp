#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    LL sum = 0, sumsp = 0;
    for (auto& x: a) {
        cin >> x;
        sum += x;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sumsp += 1ll * a[i] * a[j];
        }
    }
    LL inf = 1ll << 60;
    vector<LL> ans(k, inf);
    if (k == 1) {
        if (sum == 0) {
            if (sumsp == 0) ans[0] = 0;
        } else {
            if (abs(sumsp) % abs(sum) == 0) ans[0] = -sumsp / sum;
        }
    } else {
        ans[0] = -sum + 1;
        ans[1] = -sum + (sum * sum - sumsp);
        for (int i = 2; i < k; i++) {
            ans[i] = 0;
        }
    }
    if (ans == vector<LL>(k, inf)) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 0; i < k; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int ts;
    cin >> ts;
    for (int i = 1; i <= ts; i++) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}

