#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL a, b;
    cin >> a >> b;
    LL val = (LL)a * b;
    map<LL, int> cnt;
    for (LL i = 2; i * i <= a; i++) {
        while (a % i == 0) {
            cnt[i]++;
            a /= i;
        }
    }
    cnt[a]++;
    for (LL i = 2; i * i <= b; i++) {
        while (b % i == 0) {
            cnt[i]++;
            b /= i;
        }
    }
    cnt[b]++;
    vector<LL> ans;
    ans.push_back(1);
    for (auto [k, v]: cnt) {
        // cout << k << ' ' << v << endl;
        vector<LL> num;
        for (auto x: ans) {
            LL t = 1;
            for (int i = 0; i < v; i++) {
                t *= k;
                num.push_back(x * t);
            }
        }
        for (auto x: num) ans.push_back(x);
        // for (auto x: ans) cout << x << ' ';
        // cout << endl;
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto x: ans) cout << x << ' ';
    cout << endl;
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