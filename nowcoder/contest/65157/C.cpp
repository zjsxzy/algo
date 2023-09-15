#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL k, a, b;
    cin >> k >> a >> b;
    if (a == b) {
        cout << a * k << endl;
        return;
    }
    priority_queue<LL, vector<LL>, greater<LL>> pq;
    pq.push(a); pq.push(b);
    set<LL> st;
    st.insert(a); st.insert(b);
    while (!pq.empty()) {
        auto x = pq.top(); pq.pop();
        k--;
        if (k == 0) {
            cout << x << endl;
            return;
        }
        if (!st.count(x + a)) {
            pq.push(x + a);
            st.insert(x + a);
        }
        if (!st.count(x + b)) {
            pq.push(x + b);
            st.insert(x + b);
        }
    }
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