#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(m), C;
    set<int> S;
    for (auto& x: A) {
        cin >> x;
        C.push_back(x);
        S.insert(x);
    }
    for (auto& x: B) {
        cin >> x;
        C.push_back(x);
    }
    sort(C.begin(), C.end());
    for (int i = 1; i < C.size(); i++) {
        if (S.count(C[i]) && S.count(C[i - 1])) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
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