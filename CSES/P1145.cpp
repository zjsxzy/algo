#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    vector<int> d;
    for (int i = 0; i < n; i++) {
        if (i == 0) d.push_back(a[i]);
        else {
            if (a[i] > d.back()) d.push_back(a[i]);
            else {
                int idx = upper_bound(d.begin(), d.end(), a[i] - 1) - d.begin();
                d[idx] = a[i];
            }
        }
    }
    cout << (int)d.size() << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}