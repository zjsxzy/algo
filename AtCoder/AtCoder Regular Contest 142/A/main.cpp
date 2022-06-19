#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL f(string x) {
    LL res = stol(x);
    for (int i = 0; i < 2; i++) {
        reverse(x.begin(), x.end());
        LL t = stol(x);
        if (t < res) res = t;
        x = to_string(t);
    }
    return res;
}

void solve() {
    LL N;
    string K;
    cin >> N >> K;
    set<LL> st;
    queue<string> q;
    q.push(K);
    while (!q.empty()) {
        auto x = q.front(); q.pop();
        LL t = stol(x);
        if (st.find(t) != st.end()) continue;
        if (t >= 1 && t <= N) st.insert(t);

        if (stol(x + '0') <= N) q.push(x + '0');
        reverse(x.begin(), x.end());
        if (stol(x) <= N) q.push(x);
        if (stol(x + '0') <= N) q.push(x + '0');
    }
    int res = 0;
    for (auto x: st) {
        if (f(to_string(x)) == stol(K)) res++;
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

