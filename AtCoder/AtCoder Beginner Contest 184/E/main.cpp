#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

const int inf = 1 << 30;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int h, w;
int st, ed;
struct edge {
    int to, cost;
};

void solve() {
    cin >> h >> w;
    vector<vector<edge> > adj(h * w + 26);
    string s[h];
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') continue;
            int cur = i * w + j;
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (x >= 0 && x < h && y >= 0 && y < w) {
                    if (s[x][y] != '#') {
                        int to = x * w + y;
                        adj[cur].push_back({to, 1});
                    }
                }
            }
            if (s[i][j] >= 'a' && s[i][j] <= 'z') {
                int c = s[i][j] - 'a';
                adj[cur].push_back({h * w + c, 1}); // virtual vertex
                adj[h * w + c].push_back({cur, 0});
            }
            if (s[i][j] == 'S') st = cur;
            if (s[i][j] == 'G') ed = cur;
        }
    }
    vector<int> dist(adj.size(), inf);
    dist[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, st});
    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int v = p.second;
        if (p.first > dist[v]) continue;
        for (edge e : adj[v]) {
            int nd = p.first + e.cost;
            if (nd < dist[e.to]) {
                dist[e.to] = nd;
                pq.push({nd, e.to});
            }
        }
    }
    int res = dist[ed];
    if (res == inf) res = -1;
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}

