#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 200005;
int n;
LL a[maxn];

void solve() {
    cin >> n;
    LL sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    LL res = 0;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        LL x = a[i];
        LL t = sum * 2 - n * x;
        if (t >= 0 && t % n == 0) {
            res += cnt[t / n];
        }
        cnt[a[i]]++;
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

