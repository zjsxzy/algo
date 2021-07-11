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
    map<LL, int> cnt;
    for (int i = 0; i < n; i++) {
        LL l, r;
        cin >> l >> r;
        cnt[l + 1]++;
        cnt[r]--;
    }

    LL cur = 0;
    vector<LL> pos, freq;
    for (auto &[k, v]: cnt) {
        cur += v;
        pos.emplace_back(k);
        freq.emplace_back(cur);
    }

    vector<pair<LL, LL>> v;
    for (int i = 1; i < pos.size(); i++) {
        LL len = pos[i] - pos[i - 1];
        v.emplace_back(freq[i - 1], len);
    }
    sort(v.rbegin(), v.rend());

    LL res = 0;
    for (auto &p: v) {
        //cout << p.first << " " << p.second << endl;
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

