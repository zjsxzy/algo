#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    int sum = 0;
    for (auto& x: a) {
        cin >> x;
        sum += x;
    }
    sort(a.begin(), a.end());
    if (target == sum) {
        cout << 0 << endl;
        return;
    }
    int max = 1e4, min = -1e4;
    if (target > sum) {
        for (int i = 0; i < n; i++) {
            sum += max - a[i];
            if (sum >= target) {
                cout << i + 1 << endl;
                return;
            }
        }
    } else {
        reverse(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            sum -= a[i] - min;
            if (sum <= target) {
                cout << i + 1 << endl;
                return;
            }
        }
    }
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