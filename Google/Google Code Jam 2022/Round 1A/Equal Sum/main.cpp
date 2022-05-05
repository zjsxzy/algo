#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    LL sum = 0;
    for (int i = 0; i < min(n, 30); i++) {
        sum += 1 << i;
        cout << (1 << i) << " ";
    }
    vector<int> a;
    for (int i = 0; i < n - 30; i++) {
        a.push_back(1000000000 - i);
        sum += 1000000000 - i;
        std::cout << 1000000000 - i << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
        sum += x;
    }
    sum /= 2;
    vector<int> ans;
    for (auto x: a) {
        if (sum >= x) {
            ans.push_back(x);
            sum -= x;
        }
    }
    for (int i = 29; i >= 0; i--) {
        if (sum >> i & 1) {
            sum -= 1 << i;
            ans.push_back(1 << i);
        }
    }
    for (auto x: ans) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

