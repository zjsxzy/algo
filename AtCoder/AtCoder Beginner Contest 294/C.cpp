#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    vector<int> vec;
    map<int, int> pa, pb;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        vec.push_back(a[i]);
        pa[a[i]] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        vec.push_back(b[i]);
        pb[b[i]] = i;
    }
    sort(vec.begin(), vec.end());
    vector<int> A(n), B(m);
    for (int i = 0; i < n + m; i++) {
        if (pa.find(vec[i]) != pa.end()) {
            A[pa[vec[i]]] = i + 1;
        } else {
            B[pb[vec[i]]] = i + 1;
        }
    }
    for (auto x: A) cout << x << ' ';
    cout << endl;
    for (auto x: B) cout << x << ' ';
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