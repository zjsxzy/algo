#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<LL> a(n);
    LL sum = 0;
    for (auto& x: a) {
        cin >> x;
        sum += x;
    }
    priority_queue<LL> pq;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            pq.push(a[i] * (n - i));
        }
    }
    while (m > 0 && !pq.empty()) {
        LL x = pq.top(); pq.pop();
        m--;
        sum -= x;
    }
    cout << sum << endl;
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