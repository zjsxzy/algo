#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<LL> calc(vector<LL>& sum, int K) {
    vector<LL> f(K + 1);
    int n = sum.size();
    LL tot = sum[n - 1];
    for (int i = 0; i < n; i++) {
        if (i > K) continue;
        f[i] = max(f[i], sum[i]);
        for (int j = i + 1; j < n; j++) {
            int all = i + n - j;
            if (all <= K) {
                f[all] = max(f[all], sum[i] + tot - sum[j - 1]);
            }
        }
    }
    return f;
}

void solve() {
    int n, m, K;
    cin >> n;
    vector<LL> a(n), suma(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        suma[i + 1] = suma[i] + a[i];
    }
    cin >> m;
    vector<LL> b(m), sumb(m + 1);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        sumb[i + 1] = sumb[i] + b[i];
    }
    cin >> K;
    vector<LL> fa = calc(suma, K);
    vector<LL> fb = calc(sumb, K);
    LL res = 0;
    for (int i = 0; i <= K; i++) {
        res = max(res, fa[i] + fb[K - i]);
    }
    cout << res << endl;
}

int main() {
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       cout << "Case #" << t << ": ";
       solve();
   }
   return 0;
}

