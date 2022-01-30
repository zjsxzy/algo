#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 500005;
int ans[maxn * 2];

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i <= n * 2; i++) {
        ans[i] = -1;
    }
    ans[n] = n;
    int i = n - 1, j = n + 1;
    for (int x = n - 1; x >= 0; x--) {
        if (s[x] == 'R') {
            ans[i] = x;
            i--;
        } else {
            ans[j] = x;
            j++;
        }
    }
    for (int x = i + 1; x <= j - 1; x++) {
        cout << ans[x] << " ";
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

