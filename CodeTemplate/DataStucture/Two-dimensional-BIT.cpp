//更新区间查询区间
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll;
const int N = 1001;
int n,q;
ll a[N][N],b[N][N],c[N][N],d[N][N];
inline int lowbit(int x) {
    return x&(-x);
}
void update(ll arr[N][N],int x,int y,ll v) {
    int yy;
    for(int i = x; i <= n; i += lowbit(i)) {
        for(int j = y ; j <= n; j += lowbit(j)) {
            arr[i][j] += v;
        }
    }
}
ll query(ll arr[N][N] , int x,int y) {
    ll ret = 0;
    for(int i = x; i ; i -= lowbit(i)) {
        for(int j = y ; j ; j -= lowbit(j)) {
            ret += arr[i][j];
        }
    }
    return ret;
}
void sol() {
    scanf("%d%d",&n,&q);
    ll v;
    for(int i = 0 ,op , x1,y1,x2,y2; i < q; ++i) {

        scanf("%d%d%d%d%d",&op , &x1,&y1,&x2,&y2);
        if(op == 1) {
            scanf("%lld",&v);
            update(a , x1 , y1,v); 
            update(a , x1 , y2 + 1,-v);
            update(a , x2 + 1 , y1, -v);
            update(a , x2 + 1, y2+1 , v);

            update(b , x1 , y1, v * y1);
            update(b , x1 , y2 + 1, -v*(y2+1)); 
            update(b , x2 + 1, y1 , -v * y1);
            update(b , x2 +1 ,y2 + 1, v*(y2 + 1));

            update(c , x1 , y1,v * x1); 
            update(c , x1 , y2 + 1,-v * x1);
            update(c , x2 + 1 , y1, -v * (x2 +1) );
            update(c , x2 + 1, y2+1 , v * (x2 + 1) );

            update(d , x1 , y1, v * x1*y1);
            update(d , x1 , y2 + 1, -v*x1*(y2+1)); 
            update(d , x2 + 1, y1 , -v*(x2 + 1) * y1);
            update(d , x2 +1 ,y2 + 1, v*(x2 + 1)*(y2 + 1));
        } else {
            ll qa = query(a , x2 , y2) * (x2 + 1) * (y2 + 1) + query(a , x1 - 1, y1 - 1) * x1 * y1
                    - query(a , x1 - 1, y2) * x1 * (y2 + 1)- query(a , x2, y1 - 1) * (x2 + 1) *y1;

            ll qb = query(b ,x2 , y2) * (x2 + 1) + query(b , x1-1,y1-1) * x1
                    -query(b , x1 - 1, y2) * x1 - query(b ,x2 , y1 - 1) * (x2 + 1);

            ll qc = query(c, x2,y2) * (y2 + 1) + query(c , x1 - 1,y1 - 1) * y1
                    - query(c , x1 - 1, y2) * (y2 + 1) - query(c , x2 ,y1 -1) * y1;

            ll qd = query(d , x2 ,y2) + query(d , x1 - 1 ,y1 - 1)
                    -query(d , x1 - 1 , y2) - query(d ,x2 ,y1-1);
            printf("%lld\n",qa - qb - qc + qd);
        }
    }
}
int main() {
    freopen("input.txt","r",stdin);
    sol();
    return 0;
}

