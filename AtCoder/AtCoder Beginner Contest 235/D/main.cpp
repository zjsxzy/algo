#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 1e7;
const int num[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
int dis[MAXN + 10];

void solve() {
    int a, N;
    cin >> a >> N;
    for (int i = 1; i < MAXN; i++) dis[i] = -1;
    dis[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int x = q.front(); q.pop();

        // cout << x << " " << dis[x] << endl;

        LL xx = (LL)x * a;
        if (xx < MAXN && dis[xx] == -1) {
            dis[xx] = dis[x] + 1;
            q.push(xx);
        }

        int d = x % 10, n = 0, y = x;
        while (y) {
            y /= 10;
            n++;
        }
        if (n > 1 && n < 7 && d != 0) {
            xx = d * num[n - 1] + x / 10;
            // cout << n << " " << d << " " << xx << " " << dis[xx] << endl;
            if (xx < MAXN && dis[xx] == -1) {
                dis[xx] = dis[x] + 1;
                q.push(xx);
            }
        }
    }
    cout << dis[N] << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

