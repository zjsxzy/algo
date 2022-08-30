#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> s(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        cnt[s[i]]++;
    }
    int a = 0, b = 0, tot = 0;
    for (auto [k, v]: cnt) {
        if (v > 2) {
            cout << "NO" << endl;
            return;
        } else if (v == 2) {
            a++;
            b++;
        } else if (v == 1) {
            tot++;
        }
    }
    if (a + b + tot > 2 * k) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       cout << "Case #" << t << ": ";
       solve();
   }
   return 0;
}

