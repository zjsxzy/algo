#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int x;
    cin >> x;
    vector<int> num;
    while (x) {
        num.push_back(x % 10);
        x /= 10;
    }
    if (num.size() == 1) {
        if (num[0] % 4 == 0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
        return;
    }
    for (int i = 0; i < num.size(); i++) {
        for (int j = i + 1; j < num.size(); j++) {
            int y = num[i] * 10 + num[j], z = num[j] * 10 + num[i];
            if (y % 4 == 0 || z % 4 == 0) {
                cout << "YES" << '\n';
                return;
            }
        }
    }
    cout << "NO" << '\n';
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