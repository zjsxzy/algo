/*
ID: frankzh1
TASK: starry
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 3000;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<string> s;
vector<pair<int, int>> points;
vector<char> color;
vector<double> dist;
bool vis[maxn][maxn];
char p;
int n, m;

bool inside(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void dfs(int i, int j) {
    points.emplace_back(i, j);
    vis[i][j] = true;
    for (int k = 0; k < 8; k++) {
        int x = i + dx[k], y = j + dy[k];
        if (inside(x, y) && s[x][y] == '1' && !vis[x][y]) {
            dfs(x, y);
        }
    }
}

double get_dist(double x1, double y1, double x2, double y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

char get_color() {
    int sz = points.size();
    double d = 0;
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            d += sqrt(get_dist(points[i].first, points[i].second, points[j].first, points[j].second));
        }
    }
    for (int i = 0; i < dist.size(); i++) {
        if (abs(d - dist[i]) <= 1e-6) {
            return color[i];
        }
    }
    color.push_back(p);
    p++;
    dist.push_back(d);
    return color.back();
}

void solve() {
    cin >> m >> n;
    s.resize(n);
    for (auto &x: s) {
        cin >> x;
    }
    p = 'a';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '1') {
                dfs(i, j);
                char c = get_color();
                for (auto x: points) {
                    s[x.first][x.second] = c;
                }
                points.clear();
            }
        }
    }
    for (auto &x: s) {
        cout << x << endl;
    }
}

int main() {
    freopen("starry.in", "r", stdin);
    freopen("starry.out", "w", stdout);
    solve();
    return 0;
}

