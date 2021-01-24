#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    long long res = 1;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (a[i] <= b[j]) sum++;
        }
        if (i == 0) res *= (LL)sum;
        else res *= (LL)(sum - i);
    }
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}

