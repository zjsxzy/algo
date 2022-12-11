#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int N = 1e6;
    vector<int> prime(N, 1);
    prime[1] = prime[0] = 0;
    for (int i = 2; i < N; i++) {
        if (prime[i]) {
            for (int j = 2 * i; j < N; j += i) {
                prime[j] = 0;
            }
        }
    }
    vector<int> sum(N);
    for (int i = 1; i < N; i++) {
        sum[i] = sum[i - 1] + prime[i];
    }
    int n;
    while (cin >> n) {
        cout << sum[n] << endl;
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