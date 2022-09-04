#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), odd, even;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (i % 2 == p[i] % 2) {
            if (i & 1) odd.push_back(i);
            else even.push_back(i);
        }
    }
    vector<pair<char, int>> ans;
    int sz = odd.size();
    for (int i = 0; i < sz; i++) {
        int a = odd[i], b = even[i];

        if (a > b) swap(a, b);
        while (b - a > 1) {
            ans.emplace_back('B', a);
            swap(p[a], p[a + 2]);
            a += 2;
        }
        // b - a == 1
        ans.emplace_back('A', a);
        swap(p[a], p[a + 1]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j + 2 < n; j += 2) {
            if (p[j] > p[j + 2]) {
                ans.emplace_back('B', j);
                swap(p[j], p[j + 2]);
            }
        }
        for (int j = 1; j + 2 < n; j += 2) {
            if (p[j] > p[j + 2]) {
                ans.emplace_back('B', j);
                swap(p[j], p[j + 2]);
            }
        }
    }
    //for (auto x: p) cout << x << ' ';
    //cout << endl;
    cout << (int)ans.size() << endl;
    for (auto x: ans) cout << x.first << ' ' << x.second + 1 << endl;
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

