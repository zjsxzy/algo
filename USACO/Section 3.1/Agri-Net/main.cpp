/*
ID: frankzh1
TASK: agrinet
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 105;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    int res = 0, source = 0;
    vector<bool> vst(n);
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;
    set<pair<int, int>> q;
    q.insert({0, source});
    for (int i = 0; i < n; i++) {
        auto top = q.begin();
        int d = top->first, u = top->second;
        vst[u] = true;
        res += d;
        q.erase(q.begin());

        for (int j = 0; j < n; j++) {
            if (!vst[j] && mat[u][j] < dist[j]) {
                q.erase({dist[j], j});
                dist[j] = mat[u][j];
                q.insert({mat[u][j], j});
            }
        }
    }
    cout << res << endl;
}

int main() {
    freopen("agrinet.in", "r", stdin);
    freopen("agrinet.out", "w", stdout);
    solve();
    return 0;
}

