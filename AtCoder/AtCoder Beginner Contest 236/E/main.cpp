#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 100005;
const double eps = 1e-5;
int n;
int a[maxn];
double b[maxn], f[maxn], g[maxn];

bool check(bool greater) {
    for (int i = 0; i <= n; i++) {
        f[i] = 0; g[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        f[i] = max(f[i - 1], g[i - 1]) + b[i];
        g[i] = f[i - 1];
    }
    if (!greater) return max(f[n], g[n]) > -eps;
    else return max(f[n], g[n]) > 1 - eps;
}

void mean() {
    double lo = 0, hi = 1e9;
    while (hi - lo >= eps) {
        double mid = (lo + hi) / 2;
        for (int i = 1; i <= n; i++) {
            b[i] = a[i] - mid;
        }
        if (check(0)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    printf("%.3f\n", lo);
}

void median() {
    int lo = 0, hi = 1e9;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        for (int i = 1; i <= n; i++) {
            if (a[i] >= mid) b[i] = 1;
            else b[i] = -1;
        }
        if (check(1)) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    printf("%d\n", hi);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    mean();
    median();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

