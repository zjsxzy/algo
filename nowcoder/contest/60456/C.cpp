#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> mx(9);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if (a == 0) {
            int d = max(mx[b], mx[b + 1]);
            mx[b] = d + 3;
            mx[b + 1] = d + 1;  
        } else if (a == 90) {
            int d = max(mx[b], max(mx[b + 1], mx[b + 2]) - 1);
            mx[b] = mx[b + 1] = mx[b + 2] = d + 2;
        } else if (a == 180) {
            int d = max(mx[b] - 2, mx[b + 1]);
            mx[b] = mx[b + 1] = d + 3;
        } else if (a == 270) {
            int d = max(mx[b], max(mx[b + 1], mx[b + 2]));
            mx[b] = mx[b + 1] = d + 1;
            mx[b + 2] = d + 2;
        }
    }
    for (int i = 1; i <= 8; i++) {
        cout << mx[i] << ' ';
    }
    cout << endl;
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