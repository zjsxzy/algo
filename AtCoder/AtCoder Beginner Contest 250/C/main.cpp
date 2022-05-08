#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 200005;
int a[maxn], p[maxn];
void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        a[i] = i;
        p[i] = i;
    }
    while (q--) {
        int x;
        cin >> x;
        if (p[x] == n) {
            int t = a[p[x] - 1];
            swap(a[p[x]], a[p[x] - 1]);
            p[x]--;
            p[t]++;
        } else {
            int t = a[p[x] + 1];
            swap(a[p[x]], a[p[x] + 1]);
            p[x]++;
            p[t]--;
        }
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

