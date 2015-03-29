#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <climits>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

const int maxn = 100000 + 5;
/*
 * Count inversion pairs by merge sort
 * Notice that the array is a[1], a[2], ..., a[N]
 */
struct MergeSortForInv {
	int n;
	LL tot;
	int a[maxn], tmp[maxn];

	void init(int n) {
		this->n = n;
		tot = 0;
	}

	void add(int pos, int num) {
		a[pos] = num;
	}

	void merge(int l, int mid, int r)
	{
	    int i, j, t;
	    t = l;
	    i = l;
	    j = mid + 1;
	    while (t <= r)
	    {
	        if ((i <= mid) && ((j > r) || (a[i] > a[j])))
	        {
	            tmp[t] = a[i];
	            i++;
	        }
	        else
	        {
	            tmp[t] = a[j];
	            j++;
	            tot += i-l;
	        }
	        t++;
	    }
	    for (i = l; i <= r; i++)
	        a[i] = tmp[i];
	}

	void mergesort(int l, int r)
	{
	    int mid;
	    mid = (l + r) / 2;
	    if (l != r)
	    {
	        mergesort(l, mid);
	        mergesort(mid + 1, r);
	        merge(l, mid, r);
	    }
	}

	LL solve() {
		mergesort(1, n);//Notice merge a[1]...a[N]!
		return tot;
	}
}mg;
int n;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &n);
    mg.init(n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        mg.add(i, x);
    }
    LL ret = mg.solve();
    cout << ret << endl;
	return 0;
}

