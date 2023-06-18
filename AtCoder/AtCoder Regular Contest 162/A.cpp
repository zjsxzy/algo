#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = i + 1; j < n; j++) {
            if (p[j] < p[i]) {
                flag = false;
                break;
            }
        }
        res += flag;
    }
    cout << res << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}