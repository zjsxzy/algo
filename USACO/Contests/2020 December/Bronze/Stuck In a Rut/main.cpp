#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<string> dir(n);
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> dir[i] >> x[i] >> y[i];
    }

    vector<pair<int, pair<int, int>>> dist;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (dir[i] == "E" && dir[j] == "E" && y[i] == y[j] && x[j] > x[i]) {
                dist.push_back({x[j] - x[i], {i, j}});
            }
            if (dir[i] == "N" && dir[j] == "N" && x[i] == x[j] && y[j] > y[i]) {
                dist.push_back({y[j] - y[i], {i, j}});
            }
            if (dir[i] == "E" && dir[j] == "N" && y[i] >= y[j] && x[i] <= x[j]) {
                if (y[i] - y[j] < x[j] - x[i]) {
                    dist.push_back({x[j] - x[i], {i, j}});
                }
            }
            if (dir[i] == "N" && dir[j] == "E" && x[i] >= x[j] && y[i] <= y[j]) {
                if (x[i] - x[j] < y[j] - y[i]) {
                    dist.push_back({y[j] - y[i], {i, j}});
                }
            }
        }
    }
    sort(dist.begin(), dist.end());
    vector<int> res(n, INT_MAX);
    vector<pair<int, int>> update;
    for (int k = 0, kk = 0; k < dist.size(); k = kk) {
        update.clear();
        while (kk < dist.size() && dist[k].first == dist[kk].first) {
            int t = dist[kk].first, i = dist[kk].second.first, j = dist[kk].second.second;
            if (dir[j] == dir[i]) update.push_back({i, t});
            else {
                if (res[j] == INT_MAX) update.push_back({i, t});
            }
            kk++;
        }
        for (int u = 0; u < update.size(); u++) {
            int i = update[u].first, t = update[u].second;
            res[i] = min(res[i], t);
        }
    }
    for (int i = 0; i < n; i++) {
        if (res[i] == INT_MAX) cout << "Infinity" << endl;
        else cout << res[i] << endl;
    }
}

int main() {
    solve();
    return 0;
}

