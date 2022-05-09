#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    priority_queue<LL, vector<LL>, greater<LL>> pq;
    LL res = 0;
    for (int i = 0; i < n; i++) {
        LL p;
        cin >> p;
        if (!pq.empty()) {
            auto x = pq.top();
            if (p > x) {
                res += (p - x);
                pq.pop();
                pq.push(p);
            }
        }
        pq.push(p);
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

