#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    LL base = 131, mod = 1000000007;
    LL Left = 0, Right = 0, Mul = 1;
    for (int i = 0; i < n; i++) {
        Left = (Left * base + s[i]) % mod;
        Mul = Mul * base % mod;
    }
    Right = Left;
    LL left = 0, right = 0, mul = 1;
    int best = -1;
    for (int i = n - 1; i >= 0; i--) {
        left = (left * base + s[i]) % mod;
        right = (right + mul * s[i]) % mod;

        Left = (Left * base + s[i]) % mod;
        Right = (Right + Mul * s[i]) % mod;

        if (left == right && Left == Right) {
            best = i;
            break;
        }
        Mul = Mul * base % mod;
        mul = mul * base % mod;
    }
    string add = s.substr(best, n - best);
    cout << add << endl;
}

int main() {
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       cout << "Case #" << t << ": ";
       solve();
   }
   return 0;
}

