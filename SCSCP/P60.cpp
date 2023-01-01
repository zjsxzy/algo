#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int calc(string s) {
    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
        sum += (i + 1) * (s[i] - '0');
    }
    return sum;
}

bool balance(int x) {
    string s = to_string(x);
    for (int i = 1; i < s.size(); i++) {
        string sa = s.substr(0, i), sb = s.substr(i, s.size() - i);
        reverse(sa.begin(), sa.end());
        int a = calc(sa), b = calc(sb);
        if (a == b) return true;
    }
    return false;
}

void solve() {
    LL n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (balance(i)) {
            res++;
        }
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