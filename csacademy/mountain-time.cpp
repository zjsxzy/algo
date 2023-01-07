#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1005;
int h[maxn][maxn], ans[maxn][maxn], vst[maxn][maxn];
int N, M;
struct union_find{
    int n;
    vector<int> par, siz, maxval;
    vector<vector<int>> groups;
    union_find(int n_) : n(n_){
        par.resize(n_);
        maxval.resize(n_);
        siz.resize(n_, 1);
        groups.assign(n_, {});
        for(int i=0; i<n_; i++) {
            par[i] = i;
            maxval[i] = h[i / M][i % M];
            groups[i].push_back(i);
        }
    }
    int root(int X){
        if(par[X] == X) return X;
        return par[X] = root(par[X]);
    }
    bool same(int X, int Y){
        return root(X) == root(Y);
    }
    void unite(int X, int Y, int cost){
        X = root(X);
        Y = root(Y);
        if(X == Y) return;
        if(siz[Y] < siz[X]) std::swap(X, Y);
        if (maxval[X] > maxval[Y]) {
            for (auto x: groups[Y]) {
                ans[x / M][x % M] = cost;
            }
            groups[Y].clear();
        } else if (maxval[X] < maxval[Y]) {
            for (auto x: groups[X]) {
                ans[x / M][x % M] = cost;
            }
            groups[X].clear();
        }
        par[X] = Y;
        maxval[Y] = max(maxval[X], maxval[Y]);
        siz[Y] += siz[X];
        siz[X] = 0;
        for (auto x: groups[X]) groups[Y].push_back(x);
    }
};

void solve() {
    cin >> N >> M;
    memset(h, 0, sizeof(h));
    memset(ans, 0, sizeof(ans));
    memset(vst, 0, sizeof(vst));
    vector<pair<int, int>> vec;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> h[i][j];
            vec.push_back({-h[i][j], i * M + j});
        }
    }
    union_find dsu(N * M);
    sort(vec.begin(), vec.end());
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};
    for (auto [val, loc]: vec) {
        int i = loc / M, j = loc % M;
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni >= 0 && ni < N && nj >= 0 && nj < M && vst[ni][nj]) {
                dsu.unite(i * M + j, ni * M + nj, -val);
            }
        }
        vst[i][j] = true;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << h[i][j] - ans[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}