#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<LL> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> y[i];
    set<tuple<LL, LL, LL>> st;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            LL A = 2 * (x[j] - x[i]);
            LL B = 2 * (y[j] - y[i]);
            LL C = (x[j] * x[j] - x[i] * x[i]) + (y[j] * y[j] - y[i] * y[i]);
            LL g = gcd(gcd(A, B), C);
            A /= g; B /= g; C /= g;
            if (A < 0 || (A == 0 && B < 0)) {
                A = -A; B = -B; C = -C;
            }
            st.insert(make_tuple(A, B, C));
        }
    }
    cout << st.size() << endl;
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