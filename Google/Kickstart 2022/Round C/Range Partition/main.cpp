#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solution(int n, LL m) {
    vector<int> ans;
    vector<int> vst(n + 1);
    while (m) {
        for (int i = n; i >= 1; i--) {
            if (vst[i]) continue;
            if (i <= m) {
                ans.push_back(i);
                vst[i] = true;
                m -= i;
            }
        }
    }
    cout << "POSSIBLE" << endl;
    cout << ans.size() << endl;
    for (auto x: ans) cout << x << ' ';
    cout << endl;
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    int s = n * (n + 1) / 2;
    if (1ll * s * x % (x + y) != 0) {
        cout << "IMPOSSIBLE" << '\n';
    } else {
        LL t = 1ll * s * x / (x + y);
        solution(n, t);
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

