#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    std::cin >> n;
    vector<int> A(n), B(n);
    vector<int> P(n + 1);
    for (int i = 0; i < n; i++) std::cin >> A[i];
    for (int i = 0; i < n; i++) {
        std::cin >> B[i];
        P[B[i]] = i;
    }
    vector<int> f;
    for (int i = 0; i < n; i++) {
        int x = P[A[i]];
        auto it = lower_bound(f.begin(), f.end(), x);
        if (it == f.end()) {
            f.push_back(x);
        } else {
            *it = x;
        }
    }
    cout << n - f.size() << endl;
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