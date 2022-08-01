#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int s;
    cin >> s;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        int sum = 0, y = x;
        vector<int> vst(10);
        while (y) {
            vst[y % 10] = true;
            sum += y % 10;
            y /= 10;
        }
        if (sum == s) {
            cout << x << endl;
            return;
        }
        if (sum < s) {
            for (int i = x % 10 + 1; i < 10; i++) {
                if (vst[i]) continue;
                q.push(x * 10 + i);
            }
        }
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

