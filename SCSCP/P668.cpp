#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    auto check = [&](int k) {
        vector<int> s(k);
        for (int i = 0; i < n; i++) {
            bool find = false;
            for (int j = 0; j < k; j++) {
                if (s[j] + a[i] <= c) {
                    s[j] += a[i];
                    find = true;
                    break;
                }
            }
            if (!find) return false;
        }
        return true;
    };
    for (int i = 1; i <= n; i++) {
        if (check(i)) {
            cout << i << endl;
            return;
        }
    }
}

int main() {
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

