#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    map<char, int> cnt;
    for (auto c: s) cnt[c]++;
    if (cnt['1'] == 1 && cnt['2'] == 2 && cnt['3'] == 3) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}