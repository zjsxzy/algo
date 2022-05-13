#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
vector<int> sum;

bool check(int x) {
    for (int i = 1; i <= n; i++) {
        int j = lower_bound(sum.begin(), sum.end(), sum[n] - x + sum[i - 1]) - sum.begin();
        if (sum[i - 1] > x) return false;
        int zero = j - i + 1 - (sum[j] - sum[i - 1]);
        if (zero <= x) return true;
    }
    return false;
}

void solve() {
    string str;
    cin >> str;
    n = str.size();
    sum.resize(n + 1);
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + (str[i - 1] == '1');
    }
    int lo = 0, hi = n;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (check(mid)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

