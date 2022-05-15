#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sum = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            int l = i - 1, r = i + 1;
            bool flag = false;
            while (l >= 0 && r < n && s[l] == 'A' && s[r] == 'C') {
                sum++;
                l--;
                r++;
                flag = true;
            }
            if (flag) cnt++;
        }
    }
    cout << min(sum, 2 * cnt) << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

