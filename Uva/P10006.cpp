#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL mod_pow(LL x, LL n, LL mod) {
    LL res = 1;
    while (n) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

bool check(int n) {
    for (int i = 2; i < n; i++) {
        if (mod_pow(i, n, n) != i) return 0;
    }
    return 1;
}

void solve() {
    vector<int> prime(65000, 1);
    for (int i = 2; i < 65000; i++) {
        if (prime[i]) {
            for (int j = 2 * i; j < 65000; j += i) {
                prime[j] = 0;
            }
        }
    }
    int n;
    while (cin >> n) {
        if (n == 0) break;
        if (!prime[n] && check(n)) cout << "The number " << n << " is a Carmichael number." << endl;
        else cout << n << " is normal." << endl;
    }
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}