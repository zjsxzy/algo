#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    map<int, int> freq;
    int res = 0;
    for (int i = 0, j = 0; i < n; ) {
        while (j < n && freq[a[j]] == 0) {
            freq[a[j]]++;
            j++;
        }
        res = max(res, j - i);
        freq[a[i]]--;
        i++;
    }
    cout << res << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}