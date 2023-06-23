#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    std::cin >> n >> k;
    string s;
    std::cin >> s;
    map<char, int> cnt;
    for (auto c: s) cnt[c]++;
    vector<char> ans;
    int i, j;
    for (i = n - 1, j = 0; i >= 0 && j < k - 1; i--, j++) {
        if (cnt[s[i]] <= 1) {
            std::cout << -1 << endl;
            return;
        }
        ans.push_back(s[i]);
        cnt[s[i]]--;
    }
    std::cout << k << endl;
    std::cout << s.substr(0, i + 1) << endl;;
    reverse(ans.begin(), ans.end());
    for (auto c: ans) std::cout << c << endl;
    std::cout << endl;
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