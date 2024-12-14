#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    LL S;
    cin >> S;
    vector<int> a(n);
    LL sum = 0;
    for (auto& x: a) {
        cin >> x;
        sum += x;
    }
    S %= sum;
    vector<LL> A(n + n);
    A[0] = a[0];
    for (int i = 1; i < 2 * n; i++) {
        A[i] = A[i - 1] + a[i % n];
    }
    for (int i = 0; i < n; i++) {
        auto j = lower_bound(A.begin(), A.end(), A[i] + S) - A.begin();
        if (A[j] - A[i] == S) {
            cout << "Yes" << '\n';
            return;
        }
    }
    cout << "No" << '\n';
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