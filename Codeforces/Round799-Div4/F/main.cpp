#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int cnt[11];
bool found;

void dfs(int n, int s) {
    if (n == 3) {
        if (s % 10 == 3) {
            found = true;
        }
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (cnt[i]) {
            cnt[i]--;
            dfs(n + 1, s + i);
            cnt[i]++;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x % 10]++;
    }
    found = false;
    for (int i = 0; i < 10; i++) {
        if (cnt[i]) {
            cnt[i]--;
            dfs(1, i);
            cnt[i]++;
        }
    }
    if (found) cout << "YES" << endl;
    else cout << "NO" << endl;
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

