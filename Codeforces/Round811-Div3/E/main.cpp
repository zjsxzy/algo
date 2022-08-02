#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool has5 = false;
    for (auto& x: a) {
        cin >> x;
        if (x % 5 == 0) has5 = true;
    }
    auto check = [&]{
        for (auto x: a) if (x != a.front()) return false;
        return true;
    };
    if (has5) {
        for (auto& x: a) {
            if (x % 10 == 5) x += 5;
        }
        if (check()) cout << "YES" << endl;
        else cout << "NO" << endl;
    } else {
        for (auto& x: a) {
            while (x % 10 != 2) {
                x += x % 10;
            }
            x %= 20;
        }
        if (check()) cout << "YES" << endl;
        else cout << "NO" << endl;
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

