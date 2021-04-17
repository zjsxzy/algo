#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 1005;
int cnta[MAXN], cntb[MAXN];
void solve() {
    int n, m;
    cin >> n >> m;
    memset(cnta, 0, sizeof(cnta));
    memset(cntb, 0, sizeof(cntb));
    vector<int> a(n), b(m);
    for (auto &x : a) {
        cin >> x;
        cnta[x]++;
    }
    for (auto &x : b) {
        cin >> x;
        cntb[x]++;
    }
    vector<int> res;
    for (int i = 1; i <= 1000; i++) {
        if (cnta[i] == 1 && cntb[i] == 0) {
            res.push_back(i);
        }
        if (cnta[i] == 0 && cntb[i] == 1) {
            res.push_back(i);
        }
    }
    sort(res.begin(), res.end());
    for (auto &x : res) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

