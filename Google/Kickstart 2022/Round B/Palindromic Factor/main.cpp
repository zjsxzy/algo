#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

bool palindrome(LL x) {
    string s = to_string(x);
    int sz = s.size();
    if (sz == 1) return true;
    for (int i = 0; i < sz / 2; i++) {
        if (s[i] != s[sz - i - 1]) return false;
    }
    return true;
}

void solve() {
    LL n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= (int)sqrt(n); i++) {
        if (n % i == 0) {
            if (palindrome(i)) {
                res++;
            }
            if (i != n / i && palindrome(n / i)) {
                res++;
            }
        }
    }
    cout << res << endl;
}

int main() {
    int ts;
    cin >> ts;
    for (int i = 1; i <= ts; i++) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}

