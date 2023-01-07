#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 3000005;
int prime[N];

void init() {
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i < N; i++) {
        if (!prime[i]) {
            for (int j = i + i; j < N; j += i) {
                prime[j] = 1;
            }
        }
    }
}

void solve() {
    LL n;
    cin >> n;
    for (LL p = 2; p < N; p++) {
        if (prime[p]) continue;
        LL p2 = p * p;
        if (n % p2 != 0) continue;
        LL q = n / p2;
        if (q < N) {
            if (!prime[q]) {
                cout << p << ' ' << q << endl;
                return;
            }
        } else {
            cout << p << ' ' << q << endl;
            return;
        } 
    }
    for (LL q = 2; q < N; q++) {
        if (n % q != 0) continue;
        LL p = sqrt(n / q);
        if (p * p * q == n) {
            cout << p << ' ' << q << endl;
            return;
        }
    }
}

int main() {
    init();
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}