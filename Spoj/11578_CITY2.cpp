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

const int maxn = 100005;
int rmq[2*maxn];
struct ST {
	int mm[2*maxn];
	int best[20][2*maxn];
	void init(int n) {
		int i,j,a,b;
		mm[0]=-1;
		for(i=1; i<=n; i++) {
			mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
			best[0][i]=i;
		}
		for(i=1; i<=mm[n]; i++) {
			for(j=1; j<=n+1-(1<<i); j++) {
				a=best[i-1][j];
				b=best[i-1][j+(1<<(i-1))];
				best[i][j]=rmq[a] < rmq[b]?a:b;
			}
		}
	}
	int query(int a, int b) {
		if(a > b)	swap(a, b);
		int t;
		t=mm[b-a+1];
		a=best[t][a];
		b=best[t][b-(1<<t)+1];
		return rmq[a] < rmq[b] ? a : b;
	}
}st;
int n;
int p[maxn];

int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}

int main() {
	int cas = 1;
	while (~scanf("%d", &n)) {
		printf("Case %d: ", cas++);
		int tot = 0;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			rmq[i] = x;
		}
		st.init(n);
		for (int i = 0; i < n; i++)
			p[i] = i;
		map<int, int> last;
		for (int i = 0; i < n; i++) {
			int x = rmq[i];
			if (last.find(x) != last.end()) {
				if (i - last[x] > 1) {
					int Min = rmq[st.query(last[x] + 1, i - 1)];
					if (Min > x) p[find(i)] = find(last[x]);
				} else {
					p[find(i)] = find(last[x]);
				}
			}
			last[x] = i;
		}
		int ret = 0;
		for (int i = 0; i < n; i++)
			if (rmq[i] && find(i) == i) ret++;
		printf("%d\n", ret);
	}
	return 0;
}