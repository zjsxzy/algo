#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    vector<int> score(5);
    for (auto& x: score) cin >> x;
    vector<pair<int, string>> vec;
    for (int s = 1; s < (1 << 5); s++) {
        int cnt = 0;
        string name = "";
        for (int i = 0; i < 5; i++) {
            if (s >> i & 1) {
                name += (char)('A' + i);
                cnt += score[i];
            }
        }
        vec.push_back({-cnt, name});
    }
    sort(vec.begin(), vec.end());
    for (auto e: vec) {
        cout << e.second << '\n';
    }
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