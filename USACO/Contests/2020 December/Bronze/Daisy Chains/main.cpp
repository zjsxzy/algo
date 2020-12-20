#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 105;
int n;
int a[MAXN], sum[MAXN];

void solve() {
    cin >> n;
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    int res = n;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int s = sum[j] - sum[i - 1], avg;
            if (s % (j - i + 1) == 0) {
                avg = s / (j - i + 1);
                for (int k = i; k <= j; k++) {
                    if (a[k] == avg) {
                        res++;
                        break;
                    }
                }
            }
        }
    }
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}

