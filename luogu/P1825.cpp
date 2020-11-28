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

const int inf = 1e8;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
struct edge {
    int to, cost;
};

void solve() {
    int h, w;
    int st, ed;
    cin >> h >> w;
    vector<vector<edge> > adj(h * w);
    map<char, vector<int>> mp;
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
            if (s[i][j] >= 'A' && s[i][j] <= 'Z') {
                mp[s[i][j]].push_back(cur);
            }
            if (s[i][j] == '@') st = cur;
            if (s[i][j] == '=') ed = cur;
        }
    }
    vector<int> dist(adj.size(), inf);
    dist[st] = 0;
    queue<pair<int, int>> q;
    q.push({0, st});
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int v = p.second;
        if (v == ed) {
            cout << dist[v] << endl;
            return;
        }
        for (edge e : adj[v]) {
            int nd = p.first + e.cost;
            int i = e.to / w, j = e.to % w;
            if (s[i][j] >= 'A' && s[i][j] <= 'Z') {
                if (mp[s[i][j]].size() == 2) {
                    if (e.to == mp[s[i][j]][0]) {
                        dist[mp[s[i][j]][1]] = nd;
                        q.push({nd, mp[s[i][j]][1]});
                    } else {
                        dist[mp[s[i][j]][0]] = nd;
                        q.push({nd, mp[s[i][j]][0]});
                    }
                }
            } else if (nd < dist[e.to]) {
                dist[e.to] = nd;
                q.push({nd, e.to});
            }
        }
    }
}

int main() {
    solve();
    return 0;
}
