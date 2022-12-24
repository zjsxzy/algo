#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), vst(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(m);
    vector<int> s;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        b[i]--;
        vst[b[i]] = 1;
        s.push_back(a[b[i]]);
    }
    LL res = 0;
    for (int i = 0; i < n; i++) {
        if (!vst[i]) res += a[i];
    }
    sort(s.begin(), s.end());
    int i = 0, j = m - 1;
    while (i <= j) {
        if (s[i] < res && res > s[j]) {
            res += res;
            i++;
        } else {
            res += s[j];
            j--;
        }
    }
    cout << res << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}