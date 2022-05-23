#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mxa = 0;
    for (auto& x: a) {
        cin >> x;
        mxa = max(mxa, x);
    }
    int m;
    cin >> m;
    vector<int> b(m);
    int mxb = 0;
    for (auto& x: b) {
        cin >> x;
        mxb = max(mxb, x);
    }
    if (mxa >= mxb) {
        cout << "Alice" << '\n';
    } else {
        cout << "Bob" << '\n';
    }
    if (mxb >= mxa) {
        cout << "Bob" << '\n';
    } else {
        cout << "Alice" << '\n';
    }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

