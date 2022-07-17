#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        vec.push_back({a[i], i});
        vec.push_back({b[i], i});
    }
    sort(vec.begin(), vec.end());
    vector<int> cnt(n);
    vector<int> ans(m + 2);
    int tot = 0, pi = 0, pj = 0;
    for (int i = 1, j = 1; i <= m; i++) {
        while (j <= m && tot < n) {
            while (pj < 2 * n && vec[pj].first == j) {
                if (cnt[vec[pj].second] == 0) {
                    tot++;
                }
                cnt[vec[pj].second]++;
                pj++;
            }
            j++;
        }

        if (tot == n) {
            ans[j - i]++;
            ans[m + 1 - i + 1]--;
        }

        while (pi < 2 * n && vec[pi].first == i) {
            cnt[vec[pi].second]--;
            if (cnt[vec[pi].second] == 0) {
                tot--;
            }
            pi++;
        }
    }
    for (int i = 1; i <= m; i++) {
        ans[i + 1] += ans[i];
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

