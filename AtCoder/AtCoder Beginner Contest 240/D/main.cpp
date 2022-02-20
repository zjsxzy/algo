#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 200005;
int n;
int a[maxn];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>> st;
    st.push_back({a[1], 1});
    cout << 1 << endl;
    for (int i = 2; i <= n; i++) {
        auto t = st.back();
        int k;
        // cout << a[i] << " " << t.first << " " << t.second << endl;
        // push
        if (a[i] == t.first) {
            k = t.second + 1;
        } else {
            k = 1;
        }
        st.push_back({a[i], k});
        // pop
        if (a[i] == k) {
            while (!st.empty()) {
                auto p = st.back();
                if (p.first != a[i]) {
                    break;
                }
                st.pop_back();
            }
        }
        cout << st.size() << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

