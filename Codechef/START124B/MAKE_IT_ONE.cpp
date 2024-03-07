#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int L, R;
    cin >> L >> R;
    int N = R - L + 1;
    if (N % 2 == 0) {
        for (int i = L; i < R; i += 2) {
            cout << i + 1 << ' ' << i << ' ';
        }
        cout << endl;
    } else {
        if (L % 2 == 0) cout << -1 << endl;
        else if (N == 1) cout << L << endl;
        else {
            cout << L + 2 << ' ' << L << ' ' << L + 1 << ' ';
            for (int i = L + 3; i < R; i += 2) {
                cout << i + 1 << ' ' << i << ' ';
            }
            cout << endl;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}