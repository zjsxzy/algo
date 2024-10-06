#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

//BEGIN CUT HERE

using Int = long long;
template<Int MOD = 1000000007>
struct Mod{
  Int prev=0;
  vector<Int> fact,inv,finv;
  Mod(){}
  Mod(Int n){init(n);}

  Int pow(Int x,Int n){
    Int res=1;
    while(n){
      if(n&1) (res*=x)%=MOD;
      (x*=x)%=MOD;
      n>>=1;
    }
    return res;
  }

  Int inverse(Int a){
    return pow(a,MOD-2);
  }

  void init(Int n){
    if(prev>=n) return;
    prev=n;
    fact=inv=finv=vector<Int>(n);

    fact[0]=1;
    for(Int i=1;i<n;i++)
      fact[i]=(fact[i-1]*i)%MOD;

    inv[1]=1;
    for(Int i=2;i<n;i++)
      inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;

    finv[0]=1;
    for(Int i=1;i<n;i++)
      finv[i]=finv[i-1]*inv[i]%MOD;
  }

  Int comb(Int n,Int k){
    Int res=1;
    for(Int i=0;i<k;i++){
      res*=(n-i)%MOD;
      res%=MOD;
      res*=inverse(i+1);
      res%=MOD;
    }
    return res;
  }

  //only for prime MOD
  Int C(Int n,Int k){
    if(k<0||k>n) return 0;
    return fact[n]*finv[k]%MOD*finv[n-k]%MOD;
  }

  Int P(int n,int k){
    if(k<0||k>n) return 0;
    return fact[n]*finv[n-k]%MOD;
  }

  Int H(Int n,Int k){
    return C(n+k-1,n);
  }

  Int S(Int n,Int k){
    Int res=0;
    for(Int i=1;i<=k;i++){
      Int tmp=C(k,i)*pow(i,n)%MOD;
      if((k-i)&1) res+=MOD-tmp;
      else res+=tmp;
      res%=MOD;
    }
    res=res*finv[k]%MOD;
    return res;
  }

  Int B(Int n,Int k){
    Int res=0;
    for(Int j=1;j<=k;j++){
      res+=S(n,j);
      res%=MOD;
    }
    return res;
  }

  vector<vector<Int> > D(Int n,Int m){
    vector<vector<Int> > dp(n+1,vector<Int>(m+1,0));
    dp[0][0]=1;
    for(Int i=0;i<=n;i++){
      for(Int j=1;j<=m;j++){
        if(i-j>=0) dp[i][j]=(dp[i][j-1]+dp[i-j][j])%MOD;
        else dp[i][j]=dp[i][j-1];
      }
    }
    return dp;
  }

  Int montmort(Int n){
    Int res=0,rinv=1;
    for(Int k=2;k<=n;k++){
      rinv=rinv*inverse(k)%MOD;
      if(k%2) res+=MOD-rinv;
      else res+=rinv;
      res%=MOD;
    }
    for(Int i=1;i<=n;i++) res=res*i%MOD;
    return res;
  }

  // calculate P(t) from given points in [0,N]
  Int LagrangePolynomial(vector<Int> &y,Int t){
    Int n=y.size()-1;
    init(n+1);
    Int num=1;
    for(Int i=0;i<=n;i++)
      num=num*((t-i)%MOD)%MOD;
    Int res=0;
    for(Int i=0;i<=n;i++){
      Int tmp=(y[i]*num%MOD)*inverse((t-i)%MOD)%MOD;
      tmp=tmp*finv[i]%MOD;
      tmp=tmp*finv[n-i]%MOD;
      if((n-i)&1) tmp=MOD-tmp;
      res=(res+tmp)%MOD;
    }
    return res;
  }
};
//END CUT HERE

const int mod = 1e9 + 7;

LL qpow(LL x, LL n) {
    LL res = 1;
    for (; n; n >>= 1) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    // LL res = 0;
    // for (int i = 1; i <= n; i++) {
    //     res = (res + qpow(i, k)) % mod;
    // }
    // cout << res << endl;
    vector<Int> y(k+2,0);
    const Int MOD = 1e9+7;
    Mod<MOD> mod;
    for(Int i=1;i<=k+1;i++) y[i]=(y[i-1]+mod.pow(i,k))%MOD;
    if(n<=k+1) cout<<y[n]<<endl;
    else cout<<mod.LagrangePolynomial(y,n)<<endl;
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