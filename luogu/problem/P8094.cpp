#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    vector<int> st;
    LL res = 0;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.back()] < a[i]) {
            res += i - st.back() + 1;
            st.pop_back();
        }
        if (!st.empty()) res += i - st.back() + 1;
        st.push_back(i);
    }
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}

