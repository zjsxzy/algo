#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 1205;
int nf, n;
vector<string> sf, s;
int diff[maxn][maxn];

void solve() {
    cin >> n;
    s.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < nf; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < 20; k++) {
                sum += (sf[i][k] != s[j][k]);
            }
            diff[i][j] = sum;
        }
    }

}

int main() {
    freopen("font.in", "r", stdin);
    cin >> nf;
    sf.resize();
    for (int i = 0; i < nf; i++) {
        cin >> sf[i];
    }
    freopen("charrec.in", "r", stdin);
    freopen("charrec.out", "w", stdout);
    solve();
    return 0;
}

