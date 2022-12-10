#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int dfs(int curr, vector<int> a) {
    if (curr == -1) return 0;
    vector<int> S, T;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] >> curr & 1) T.push_back(a[i]);
        else S.push_back(a[i]);
    }
    if (S.size() == 0) return dfs(curr - 1, T);
    if (T.size() == 0) return dfs(curr - 1, S);
    return min(dfs(curr - 1, S), dfs(curr - 1, T)) | (1 << curr);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    cout << dfs(29, a) << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}