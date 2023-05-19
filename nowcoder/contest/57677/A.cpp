#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 10;
int prime[maxn], tot;
bool vis[maxn];

void init() {
    for (int i = 2; i <= 1e5; i++) {
        if (!vis[i]) {
            prime[tot++] = i;
            for (int j = i + i; j <= 1e5; j += i) {
                vis[j] = 1;
            }
        }
    }
}

bool isPrime(int n) {
    for (int i = 0; i < tot && prime[i] * prime[i] <= n; i++) {
        if (n % prime[i] == 0) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    if (n <= 5) {
        cout << n << endl;
        return;
    }
    while (!isPrime(n)) {
        n--;
    }
    cout << n << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    init();
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}