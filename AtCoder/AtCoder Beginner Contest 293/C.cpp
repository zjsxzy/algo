#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, m, res;
int a[15][15];
set<int> st;

void dfs(int i, int j) {
    if (i == n - 1 && j == m - 1) {
        res++;
        return;
    }
    if (i + 1 < n && st.find(a[i + 1][j]) == st.end()) {
        st.insert(a[i + 1][j]);
        dfs(i + 1, j);
        st.erase(a[i + 1][j]);
    }
    if (j + 1 < m && st.find(a[i][j + 1]) == st.end()) {
        st.insert(a[i][j + 1]);
        dfs(i, j + 1);
        st.erase(a[i][j + 1]);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    res = 0;
    st.clear();
    st.insert(a[0][0]);
    dfs(0, 0);
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