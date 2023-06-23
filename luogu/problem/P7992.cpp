#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<LL> p(m + 1), q(m + 1);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        p[a]++;
        q[b]++;
    }
    vector<LL> P(2 * m + 1), Q(2 * m + 1);
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            P[i + j] += p[i] * p[j];
            Q[i + j] += q[i] * q[j];
        }
    }
    LL res = 0;
    for (int i = 0; i <= 2 * m; i++) {
        res += P[i];
        cout << res << endl;
        res -= Q[i];
    }
}

int main() {
    solve();
    return 0;
}

