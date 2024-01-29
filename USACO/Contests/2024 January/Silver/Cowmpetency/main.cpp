#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int N, Q, C;
    cin >> N >> Q >> C;
    vector<int> c(N + 1);
    for (int i = 1; i <= N; i++) cin >> c[i];
    vector<pair<int, int>> pair(Q);
    for (int i = 0; i < Q; i++) cin >> pair[i].first >> pair[i].second;
    sort(pair.begin(), pair.end());
    vector<int> mx(N + 1);
    mx[0] = 1;
    for (int i = 1; i <= N; i++) mx[i] = max(mx[i - 1], c[i]);
    for (int i = 1, j = 0; i <= N; i++) {
        if (c[i] == 0) c[i] = 1;
        mx[i] = max(mx[i], c[i]);
        for (; j < Q && pair[j].first <= i; j++) {
            // cout << i << ' ' << pair[j].first << ' ' << pair[j].second << endl;
            int idx = pair[j].second;
            c[pair[j].first] = mx[idx - 1];
            mx[pair[j].first] = max(mx[pair[j].first], c[pair[j].first]);
            if (c[idx] != 0) {
                if (c[idx] <= mx[pair[j].first]) {
                    cout << -1 << endl;
                    return;
                }
            } else {
                c[idx] = mx[pair[j].first] + 1;
                if (c[idx] > C) {
                    cout << -1 << endl;
                    return;
                }
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << c[i] << ' ';
    }
    cout << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}