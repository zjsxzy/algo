#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL n, m, k;
    cin >> n >> m >> k;
    vector<pair<LL, LL>> weight(n);
    for (int i = 0; i < n; i++) cin >> weight[i].first >> weight[i].second;
    sort(weight.begin(), weight.end());
    vector<pair<LL, LL>> vec;
    LL curr = 0, res = 0, p = 0;
    for (int i = 0; i < n; i++) {
        LL num = weight[i].second, cnt = 0;
        while (num > 0 && p < vec.size() && vec[p].first <= weight[i].first - k) {
            if (vec[p].second <= num) {
                num -= vec[p].second;
                cnt += vec[p].second;
                vec[p].second = 0;
                p++;
            } else {
                cnt = num;
                vec[p].second -= num;
                num = 0;
            }
        }
        if (num > 0 && curr < m) {
            if (m - curr <= num) cnt += m - curr, curr = m;
            else cnt += num, curr += num;
        }
        // cout << weight[i].first << ' ' << cnt << ' ' << p << endl;
        res += cnt;
        vec.push_back({weight[i].first, cnt});
    }
    cout << res << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}