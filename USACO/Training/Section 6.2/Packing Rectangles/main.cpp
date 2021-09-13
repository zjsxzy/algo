/*
ID: frankzh1
TASK: packrec
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

struct rect {
    int h, w;

    bool operator < (const rect& p) {
        return h < p.h || (h == p.h && w < p.w);
    }

    bool operator == (const rect& p) {
        return h == p.h && w == p.w;
    }
};
rect a[4], mat[4];
int vis[4];
vector<rect> ans;

void check(rect r) {
    if (r.h > r.w) swap(r.h, r.w);
    if (ans.size() == 0) {
        ans.emplace_back(r);
        return;
    }
    if (r.h * r.w < ans[0].h * ans[0].w) {
        ans.clear();
        ans.emplace_back(r);
    } else if (r.h * r.w == ans[0].h * ans[0].w) {
        ans.emplace_back(r);
    }
}

void dfs(int s) {
    if (s == 4) {
        rect r;
        // 1
        r.h = max(mat[0].h, max(mat[1].h, max(mat[2].h, mat[3].h)));
        r.w = mat[0].w + mat[1].w + mat[2].w + mat[3].w;
        check(r);

        // 2
        r.h = max(mat[0].h, max(mat[1].h, mat[2].h)) + mat[3].h;
        r.w = max(mat[3].w, mat[0].w + mat[1].w + mat[2].w);
        check(r);

        // 3
        r.h = max(mat[3].h, max(mat[0].h, mat[1].h) + mat[2].h);
        r.w = max(mat[0].w + mat[1].w, mat[2].w) + mat[3].w;
        check(r);

        // 4
        r.h = max(mat[0].h, max(mat[1].h + mat[2].h, mat[3].h));
        r.w = mat[0].w + max(mat[1].w, mat[2].w) + mat[3].w;
        check(r);

        // 5
        r.h = max(mat[0].h, mat[1].h) + mat[2].h + mat[3].h;
        r.w = max(mat[0].w, mat[1].w) + mat[2].w + mat[3].w;
        check(r);

        // 6
        if (mat[0].w <= mat[1].w && mat[1].h <= mat[3].h) {
            r.h = max(mat[0].h + mat[1].h, mat[2].h + mat[3].h);
            r.w = max(mat[1].w + mat[3].w, mat[0].w + mat[2].w);
            check(r);
        }
    }

    for (int i = 0; i < 4; i++) {
        if (!vis[i]) {
            vis[i] = true;
            mat[s].h = a[i].h;
            mat[s].w = a[i].w;
            dfs(s + 1);
            swap(mat[s].h, mat[s].w);
            dfs(s + 1);
            vis[i] = false;
        }
    }
}

void solve() {
    for (int i = 0; i < 4; i++) {
        cin >> a[i].h >> a[i].w;
    }
    memset(vis, false, sizeof(vis));
    dfs(0);
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    cout << ans[0].h * ans[0].w << endl;
    for (auto &r: ans) {
        cout << r.h << " " << r.w << endl;
    }
}

int main() {
    freopen("packrec.in", "r", stdin);
    freopen("packrec.out", "w", stdout);
    solve();
    return 0;
}

