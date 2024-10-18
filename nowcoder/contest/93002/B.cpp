#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    LL h, L, R;
    cin >> n >> k >> h >> L >> R;
    if (L >= 0) {
        cout << "impossible" << endl;
        return;
    }
    if (R < 0) {
        LL l = -(h / L) + (h % L != 0), r = -(h / R) + (h % R != 0);
        if (l <= k && k <= r) {
            int j = -h / L + (h % L != 0);
            for (int i = 0; i < k - j; i++) cout << 0 << ' ';
            for (int i = 0; i < j; i++) cout << L << ' ';
            for (int i = k; i < n; i++) cout << L << ' ';
            cout << endl;
        } else {
            cout << "impossible" << endl;
        }
    } else {
        if (h >= k) {
            if (-L * k >= h) {
                int j = -h / L + (h % L != 0);
                for (int i = 0; i < k - j; i++) cout << 0 << ' ';
                for (int i = 0; i < j; i++) cout << L << ' ';
                for (int i = k; i < n; i++) cout << L << ' ';
                cout << endl;
            } else {
                cout << "impossible" << endl;
            }
        } else {
            for (int i = 1; i < k; i++) {
                LL t = h + i * R;
                if (t >= (k - i)) {
                    LL a = -(h - (k - i)) / i;
                    for (int j = 0; j < i - 1; j++) cout << a << ' ';
                    cout << -(h - (k - i)) - (i - 1) * a << ' ';
                    for (int j = i; j < k; j++) cout << -1 << ' ';
                    for (int j = k; j < n; j++) cout << L << ' ';
                    cout << endl;
                    return;
                }
            }
            cout << "impossible" << endl;
        }
        
    }
    
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}