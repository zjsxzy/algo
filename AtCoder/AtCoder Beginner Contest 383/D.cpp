#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL n;
    cin >> n;
    LL m = sqrt(n) + 1;
    vector<LL> primes;
    vector<int> vst(m + 10);
    for (int i = 2; i <= m; i++) {
        if (!vst[i]) {
            primes.push_back(i);
            for (int j = i + i; j <= m; j += i) {
                vst[j] = 1;
            }
        }
    }
    int sz = primes.size();
    vst.assign(m, 0);
    for (int i = 0; i < sz; i++) {
        for (int j = i + 1; j < sz; j++) {
            if (primes[i] * primes[j] > m) break;
            vst[primes[i] * primes[j]] = 1;
        }
    }
    for (auto x: primes) {
        if (x * x * x * x > m) break;
        vst[x * x * x * x] = 1;
    }
    int res = 0;
    for (LL x = 1; x * x <= n; x++) {
        if (vst[x]) {
            res++;
        }
    }
    cout << res << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}