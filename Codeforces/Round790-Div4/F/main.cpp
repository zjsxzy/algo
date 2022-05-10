#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    sort(a.begin(), a.end());
    int num = a[0], cnt = 1;
    vector<int> val;
    for (int i = 1; i < n; i++) {
        if (a[i] != num) {
            if (cnt >= k) {
                val.push_back(num);
            }
            num = a[i];
            cnt = 1;
        } else {
            cnt++;
        }
    }
    if (cnt >= k) {
        val.push_back(num);
    }
    if (val.size() == 0) {
        cout << -1 << endl;
        return;
    }
    int res = 0, l = val[0], r = val[0];
    num = val[0];
    for (int i = 1; i < (int)val.size(); i++) {
        if (val[i] - val[i - 1] == 1) {
            if (val[i] - num > res) {
                res = val[i] - num;
                l = num; r = val[i];
            }
        } else {
            num = val[i];
        }
    }

    cout << l << " " << r << endl;
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

