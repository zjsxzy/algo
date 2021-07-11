#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    LL c;
    cin >> n >> c;
    vector<pair<LL, LL>> vec;
    for (int i = 0; i < n; i++) {
        LL l, r;
        cin >> l >> r;
        vec.emplace_back(l, 1);
        vec.emplace_back(r, -1);
    }
    sort(vec.begin(), vec.end());
    LL cur = 0, prev = 1;
    vector<pair<LL, LL>> ans;
    for (auto &p: vec) {
        if (p.first - prev > 1) {
            ans.emplace_back(cur, p.first - prev - 1);
        }
        if (p.second == 1) {
            if (p.first > prev) ans.emplace_back(cur, 1);
            cur++;
        } else {
            cur--;
            if (p.first > prev) ans.emplace_back(cur, 1);
        }
        prev = p.first;
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    LL res = 0;
    for (auto &p: ans) {
        cout << p.first << " " << p.second << endl;
        if (p.first == 0) break;
        if (c > p.second) {
            res += p.first * p.second;
            c -= p.second;
        } else {
            res += p.first * c;
            break;
        }
    }
    cout << res + n << endl;
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

