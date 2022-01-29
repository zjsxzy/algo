#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    LL l, w;
    cin >> n >> l >> w;
    vector<pair<LL, LL>> vec;
    for (int i = 0; i < n; i++) {
        LL x;
        cin >> x;
        vec.emplace_back(x, x + w);
    }
    sort(vec.begin(), vec.end());
    LL sum = 0;
    LL curr = 0;
    LL res = 0;
    for (int i = 0; i < n; i++) {
        if (vec[i].first <= curr) {
            sum += vec[i].second - curr;
        } else {
            sum += vec[i].second - vec[i].first;
            LL cover = vec[i].first - curr;
            if (cover % w == 0) res += cover / w;
            else res += cover / w + 1;
        }
        curr = vec[i].second;
    }
    if (curr < l) {
        LL cover = l - curr;
        if (cover % w == 0) res += cover / w;
        else res += cover / w + 1;
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

