#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 50050
#define typec int
const int nil = -1;

struct node {
    typec key;
    int l, r, f, dist;
} Lheap[N];

int a[N];
int p[N], size[N], cnt[N];

int find(int i) {
    if (i == nil) return i;
    while (Lheap[i].f != nil) i = Lheap[i].f;
    return i;
}

int Merge(int rx, int ry) {
    if (rx == nil) return ry;
    if (ry == nil) return rx;
    if (Lheap[rx].key < Lheap[ry].key) swap(rx, ry);
    int r = Merge(Lheap[rx].r, ry);
    Lheap[rx].r = r;
    Lheap[r].f = rx;
    if (Lheap[r].dist > Lheap[Lheap[rx].l].dist) swap(Lheap[rx].l, Lheap[rx].r);
    if (Lheap[rx].r == nil) Lheap[rx].dist = 0;
    else Lheap[rx].dist = Lheap[Lheap[rx].r].dist + 1;
    return rx; // return new root
}

node top(int root) {
    return Lheap[root];
}

node pop(int &root) {
    node out = Lheap[root];
    int l = Lheap[root].l, r = Lheap[root].r;
    Lheap[root].l = Lheap[root].r = Lheap[root].f = nil;
    Lheap[l].f = Lheap[r].f = nil;
    root = Merge(l, r);
    return out;
}

int abs(int x)
{
    if(x < 0) return -x;
    return x;
}

int main()
{
    int n;
    int i,j;
    while(scanf("%d",&n)&&n)
    {
        for(i = 0; i < n ; i ++)
        {
            scanf("%d",&a[i]);
            Lheap[i].key = a[i];
            Lheap[i].l = Lheap[i].r = Lheap[i].f = nil;
            Lheap[i].dist = 0;
        }
        int m = -1;
        for(i = 0; i < n ; i ++)
        {
            p[++m] = i;
            size[m] = 1;
            cnt[m] = 1;
            while(m > 0 && top(p[m]).key <= top(p[m - 1]).key)
            {
                p[m - 1] = Merge(p[m],p[m - 1]);
                size[m - 1] += size[m];
                cnt[m - 1] += cnt[m];
                m --;
                
                while(cnt[m] > (size[m] + 1)/2)
                {
                    pop(p[m]);
                    cnt[m] --;
                }
            }
        }
        int k = 0;
        long long res = 0; 
        for(i = 0 ; i <= m ; i ++)
        {
            int val = top(p[i]).key;
            for(j = 0; j < size[i]; j ++)
                res += abs(a[k ++] - val);
        }
        printf("%lld\n",res);
    }
    
    return 0;
}
