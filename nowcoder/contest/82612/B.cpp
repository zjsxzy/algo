#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 100005;
vector<int> prime;
void init() {
    prime.assign(N, 1);
    prime[1] = 0;
    for (int i = 2; i < N; i++) {
        if (prime[i]) {
            for (int j = i + i; j < N; j += i) {
                prime[j] = 0;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    
    int cnt = 0;
    for (auto x: a) {
        if (x != 3 && prime[x]) cnt++;
    }
    if (cnt == 0) {
        cout << -1 << endl;
    } else if (cnt & 1) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    init();
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}