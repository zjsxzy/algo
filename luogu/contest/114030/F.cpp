#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    std::cin >> n >> k;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < k; j++) {
            int x;
            std::cin >> x;
            sum += x;
        }
        vec.push_back({-sum, i + 1});
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < 2; i++) {
        std::cout << vec[i].second << endl;
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