/*
ID: frankzh1
TASK: fence8
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 1024;
int n, m, sum;
int a[maxn], b[maxn], bsum[maxn];

bool check(int num, int now, int q, int limit) {
    if (num == 0) return true;
    if (q > limit) return false;
    if (b[num] != b[num + 1]) now = n;
    for (int i = now; i > 0; i--) {
        if (a[i] >= bsum[num]) return true;
        if (a[i] >= b[num]) {
            a[i] -= b[num];
            if (check(num - 1, i, q + (a[i] < b[1]) ? a[i] : 0, limit)) {
                a[i] += b[num];
                return true;
            }
            a[i] += b[num];
        }
    }
    return false;
}

void solve() {
    cin >> n;
    sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + n + 1);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    sort(b + 1, b + m + 1);
    bsum[0] = 0;
    for (int i = 1; i <= m; i++) {
        bsum[i] = bsum[i - 1] + b[i];
    }
    int sum2 = sum, hi = m;
    for (int i = 1; i <= m; i++) {
        sum2 -= b[i];
        if (sum2 < 0) {
            hi = i;
            break;
        }
    }
    int res = -1;
    int lo = 0;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (check(mid, n, 0, sum - bsum[mid])) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << res << endl;
}

int main() {
    freopen("fence8.in", "r", stdin);
    freopen("fence8.out", "w", stdout);
    solve();
    return 0;
}

