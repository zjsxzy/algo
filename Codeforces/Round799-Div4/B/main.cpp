#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    for (auto& x: a) {
        cin >> x;
        cnt[x]++;
    }
    int sum = 0;
    for (auto [k, v]: cnt) {
        if (v > 1) sum += v - 1;
    }
    if (sum & 1) sum++;
    cout << n - sum << endl;
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

