#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    vector<int> k(5);
    for (auto& x: k) cin >> x;
    int cnt = 0;
    for (int i = 1; i < 5; i++) {
        cnt += (k[i] > k[0]);
    }
    cout << cnt << endl;
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