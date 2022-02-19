#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

bool is_prime(int x) {
    int cnt = 0;
    for (int i = 2; i < x; i++) {
        if (x % i == 0) cnt++;
    }
    return cnt == 0;
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> f(205);
    for (int i = 1; i <= 200; i++) {
        if (is_prime(i)) f[i] = true;
    }
    for (int x = a; x <= b; x++) {
        bool flag = true;
        for (int y = c; y <= d; y++) {
            if (f[x + y]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "Takahashi" << endl;
            return;
        }
    }
    cout << "Aoki" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

