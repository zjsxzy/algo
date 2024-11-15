#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> calc(LL x, int k) {
    vector<int> ans;
    while (x) {
        ans.push_back(x % k);
        x /= k;
    }
    return ans;
}

void solve() {
    LL k, A, B;
    cin >> k >> A >> B;
    if (A > B) swap(A, B);
    vector<int> a, b;
    a = calc(A, k);
    b = calc(B, k);
    LL res = 0, t = 1;
    // for (auto x: a) cout << x << ' ';
    // cout << endl;
    // for (auto x: b) cout << x << ' ';
    // cout << endl;
    for (int i = 0; i < a.size(); i++) {
        res += t * ((a[i] + b[i]) % k);
        t *= k;
    }
    for (int i = a.size(); i < b.size(); i++) {
        res += t * b[i];
        t *= k;
    }
    cout << res << endl;
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