#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
typedef long long LL;
const int N = 50000+10;
const LL INF = 250000000000ll;
LL n,k;
LL work(LL j,LL m) {
    LL d = j * j - j * 100000;
    LL a = 1, b = 100000 + j, c = d - m;
    LL tmp = b * b - 4 * a * c;
    if (tmp < 0) return 0;
    double l = (-b - sqrt(tmp*1.0)) / 2, r = (-b + sqrt(tmp*1.0)) / 2;
    int u = ceil(l), v = floor(r);
    if (v <= 0) return 0;
    u = max(1,u); v = min(v,(int)n);
    if (v < u){
        cout<<endl;
    }
    return v - u + 1;
}
LL check(LL m) {
    LL ret = 0;
    for (int i = 1; i <= n; i++) {
        ret += work(i,m);
       // cout<<ret<<" --- "<<endl;
    }
    return ret;
}
void solve(){
    LL l = -INF, r = INF;
    while (r > l) {
        LL m = l + (r - l)/2;
        LL t = check(m);
       // cout<<t<<" *** "<<endl;
        if (t >= k) r = m;
        else l = m+1;
    }
    cout<<r<<endl;
}
int main(){
    int T; scanf("%d",&T);
    while (T--) {
        cin>>n>>k;
        solve();
    }
    return 0;
}
