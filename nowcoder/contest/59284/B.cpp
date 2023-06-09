#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int x;
    cin >> x;
    vector<int> ans;
    int i = 1;
    while (x > 2 * i) {
        ans.push_back(i);
        x -= i;
        i++;
    }
    ans.push_back(x);
    for (auto c: ans) cout << c << ' ';
    cout << endl;
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