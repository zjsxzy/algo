/*
ID: frankzh1
TASK: pprime
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 10000005;
bool prime[MAXN];
int a, b;

void get_prime() {
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    int n = sqrt(b);
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            for (int j = 2; i * j <= b; j++) {
                prime[i * j] = false;
            }
        }
    }
}

bool palindrome(int num) {
    int x = num, res = 0;
    while (x) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res == num ? true : false;
}

void solve() {
    cin >> a >> b;
    if (b >= 10000000) b = 9999999;
    get_prime();
    for (int x = a; x <= b; x++) {
        if (prime[x] && palindrome(x)) {
            cout << x << endl;
        }
    }
}

int main() {
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
    solve();
    return 0;
}

