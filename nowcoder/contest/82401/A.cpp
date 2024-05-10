#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

bool check(int x) {
    if (x % 7 == 0) return true;
    while (x) {
        if (x % 10 == 7) return true;
        x /= 10;
    }
    return false;
}

void solve() {
    int n, a, k;
    cin >> n >> a >> k;
    int x = a + 1;
    for (int i = 0; i < k; i++) {
        if (check(x)) cout << 'p' << ' ';
        else cout << x << ' ';
        x += n;
    }
    cout << endl;
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