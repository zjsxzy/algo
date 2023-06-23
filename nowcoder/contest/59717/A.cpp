#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e6 + 5;
int p[maxn];

void prime() {
    memset(p, 0, sizeof(p));
    p[1] = 1;
    for (int i = 2; i <= 1e6; i++) {
        if (!p[i]) {
            for (int j = i + i; j <= 1e6; j += i) {
                p[j] = 1;
            }
        }
    }
}

void solve() {
    int n;
    std::cin >> n;
    bool flag = true;
    while (n) {
        if (p[n]) {
            flag = false;
            break;
        }
        n /= 10;
    }
    if (flag) std::cout << "YES" << endl;
    else std::cout << "NO" << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    std::cin >> ts;
    prime();
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}