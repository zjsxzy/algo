/*
ID: frankzh1
TASK: runround
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

bool round(int x) {
    vector<int> cnt(10);
    vector<int> digits;
    while (x) {
        if (x % 10 == 0) return false;
        cnt[x % 10]++;
        if (cnt[x % 10] > 1) return false;
        digits.emplace_back(x % 10);
        x /= 10;
    }
    reverse(digits.begin(), digits.end());
    int sz = digits.size(), pos = 0;
    vector<int> used(sz);
    while (!used[pos]) {
        used[pos] = true;
        pos = (pos + digits[pos]) % sz;
    }
    if (pos != 0) return false;
    for (int i = 0; i < sz; i++) {
        if (!used[i]) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    for (int i = n + 1; ; i++) {
        if (round(i)) {
            cout << i << endl;
            return;
        }
    }
}

int main() {
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);
    solve();
    return 0;
}

