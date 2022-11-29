#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};

void solve() {
    int n, q;
    cin >> n >> q;
    DSU dsu(n + q);
    int k = n;
    vector<int> ball(n), box(n + q);
    iota(ball.begin(), ball.end(), 0);
    iota(box.begin(), box.end(), 0);
    for (int i = 0; i < q; i++) {
        int op, x, y;
        cin >> op;
        if (op == 3) {
            cin >> x;
            x--;
            cout << box[dsu.leader(x)] + 1 << endl;
        } else if (op == 2) {
            cin >> x;
            x--;
            box[k] = x;
            if (ball[x] == -1) {
                ball[x] = k;
            } else {
                dsu.merge(ball[x], k);
            }
            k++;
        } else if (op == 1) {
            cin >> x >> y;
            x--; y--;
            if (ball[y] == -1) continue;
            if (ball[x] == -1) {
                ball[x] = ball[y];
                box[ball[x]] = x;
            } else {
                dsu.merge(ball[x], ball[y]);
            }
            ball[y] = -1;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

