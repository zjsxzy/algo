/*
ID: frankzh1
TASK: cowtour
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 155;
const double INF = 1e20;
int n;
struct Point {
    int x, y;
    double dist(const Point& p) {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
};
double dist[MAXN][MAXN], diameter[MAXN];
Point p[MAXN];
int field[MAXN];

void dfs(int u, int id) {
    field[u] = id;
    for (int v = 0; v < n; v++) {
        if (!field[v] && dist[u][v] < INF) {
            dfs(v, id);
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1' || i == j) {
                dist[i][j] = p[i].dist(p[j]);
            } else {
                dist[i][j] = INF;
            }
        }
    }

    // 1. DFS
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!field[i]) {
            cnt++;
            dfs(i, cnt);
        }
    }

    // 2. Floyd
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // 3. find diameter
    vector<double> max_d(n, 0.0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] < INF) {
                max_d[i] = max(max_d[i], dist[i][j]);
            }
        }
        diameter[field[i]] = max(diameter[field[i]], max_d[i]);
    }

    // 4. find result
    double res = INF;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (field[i] != field[j]) {
                double max_dist = max(max(diameter[field[i]], diameter[field[j]]), max_d[i] + max_d[j] + p[i].dist(p[j]));
                res = min(res, max_dist);
            }
        }
    }
    printf("%.6f\n", res);
}

int main() {
    freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w", stdout);
    solve();
    return 0;
}

