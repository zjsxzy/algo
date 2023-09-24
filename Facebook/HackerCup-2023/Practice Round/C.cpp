#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve(int cs) {
    cout << "Case #" << cs << ": ";
    int n;
    cin >> n;
    vector<int> a(2 * n - 1);
    LL sum = 0;
    for (auto& x: a) {
        cin >> x;
        sum += x;
    }
    sort(a.begin(), a.end());
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve(t);
    }
    return 0;
}