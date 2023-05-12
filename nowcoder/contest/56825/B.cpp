#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    vector<int> cnt(4005, 1);
    for (int i = 2; i <= 4000; i++) {
         for (int j = i; j <= 4000; j += i) cnt[j]++;
    }
    vector<int> sum(4005);
    for (int i = 1; i <= 4000; i++) {
        sum[i] = sum[i - 1] + (cnt[i] & 1);
    }
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        cout << sum[x] << endl;
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