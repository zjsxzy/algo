#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

//扩展欧几里得算法
void gcd(LL a, LL b, LL &d, LL &x,LL &y) {
    if (b == 0) {
        d = a;
        x = 1, y = 0;
    } else {
        gcd(b, a % b, d, y, x);
        y -= (a / b) * x;
    }
}

int n;
LL m[15], a[15];
//中国剩余定理
LL China() {
    LL M = 1, d, y, x = 0;
    for (int i = 0; i < n; i++) M *= m[i];
    for (int i = 0; i < n; i++) {
        LL w = M / m[i];
        gcd(m[i], w, d, d, y);
        x = (x + y * w * a[i]) % M;//y是乘法逆元
    }
    return (x + M) % M;
}

//已知m1,m2,m3是两两互质的正整数，求最小的正整数x，使它被m1,m2,m3除所得的余数分别是c1,c2,c3。
//孙子定理的思想便是线分别求出被其中数mi整除余1而被另外两个数整除的数Mi(i=1,2,3)，则所求数之一的便是c1M1+c2M2+c3M3。
void solve() {
    // int n;
    // scanf("%d",&n);
    // for(int i=0;i<n;i++)
    //     scanf("%lld%lld",&m[i],&a[i]);
    // printf("%lld",China(n,m,a));
    n = 2;
    m[0] = 400000000; m[1] = 399999999;
    cout << "? " << m[0] << endl;
    cin >> a[0];
    cout << "? " << m[1] << endl;
    cin >> a[1];
    LL res = China();
    cout << "! " << res << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}