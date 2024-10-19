#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n), B(n);
    for (auto& x: A) cin >> x;
    for (auto& x: B) cin >> x;
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        return A[i] < A[j];
    });
    priority_queue<int> pq;
    LL sum = 0, res = 1ll << 60;
    for (auto i: ord) {
        sum += B[i];
        pq.push(B[i]);
        while (pq.size() > k) {
            sum -= pq.top();
            pq.pop();
        }
        if (pq.size() == k) {
            res = min(res, sum * A[i]);
        }
    }
    cout << res << endl;
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