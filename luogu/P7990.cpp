#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int K, M, N;
    cin >> K >> M >> N;
    vector<pair<int, int>> patches(K + M);
    for (int i = 0; i < K; i++) {
        cin >> patches[i].first >> patches[i].second;
    }
    for (int i = K; i < K + M; i++) {
        cin >> patches[i].first;
        patches[i].second = -1;
    }
    sort(patches.begin(), patches.end());

    vector<LL> increases;
    int last_i = -1;
    LL sum_range = 0;
    for (int i = 0; i < patches.size(); i++) {
        if (patches[i].second == -1) {
            if (last_i == -1) {
                increases.push_back(sum_range);
            } else {
                LL cur_sum = 0, best_sum = 0;
                for (int j = last_i + 1, r = last_i; j < i; j++) {
                    while (r + 1 < i && (patches[r + 1].first - patches[j].first) * 2 < patches[i].first - patches[last_i].first) {
                        cur_sum += patches[++r].second;
                    }
                    best_sum = max(best_sum, cur_sum);
                    cur_sum -= patches[j].second;
                }
                increases.push_back(best_sum);
                increases.push_back(sum_range - best_sum);
            }
            last_i = i;
            sum_range = 0;
        } else {
            sum_range += patches[i].second;
        }
    }
    increases.push_back(sum_range);
    sort(increases.rbegin(), increases.rend());
    increases.resize(N);
    LL res = 0;
    for (auto val: increases) {
        res += val;
    }
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}

