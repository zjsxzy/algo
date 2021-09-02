/*
ID: frankzh1
TASK: ditch
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

#define th(x) this->x = x
const int MAXN = 200 + 10;
const int MAXM = 200 + 10;
const int inf = 0x3f3f3f3f;
struct Nod
{
	int b, next;
	int cap, flow;
	void init(int b, int cap, int next)
	{
		th(b);
		th(cap);
		th(next);
	}
};
struct SAP
{
	int E[MAXN], n;
	int h[MAXN], vh[MAXN], source, sink;
	Nod buf[MAXM * 4]; int len;
	void init(int n)
	{
		this->n = n;
		len = 0;
		memset(E, 255, sizeof(E));
	}
	void addCap(int i, int j, int cap1, int cap2 = 0)
	{
		buf[len].init(j, cap1, E[i]);
		E[i] = len++;
		buf[len].init(i, cap2, E[j]);
		E[j] = len++;
	}
	int sap(const int idx, const int maxCap)
	{
		if (idx == sink)
				return maxCap;
		int l = maxCap, d, minH = n;
		for (int i = E[idx]; i != -1; i = buf[i].next)
		{
				Nod & nod = buf[i];
				if (nod.cap-nod.flow > 0)
				{
						if (h[idx] == h[nod.b] + 1)
						{
								d = sap(nod.b, min(l, nod.cap - nod.flow));
								nod.flow += d;
								buf[i ^ 1].flow -= d;
								l -= d;
								if (h[source] == n || l == 0) return maxCap - l;
						}
						minH = min(minH, h[nod.b] + 1);
				}
		}
		if (l == maxCap)
		{
				vh[h[idx]]--;
				vh[minH]++;
				if (vh[h[idx]] == 0)
						h[source] = n;
				h[idx] = minH;
		}
		return maxCap - l;
	}
	int solve(int source, int sink)
	{
		if (source == sink) return inf;
		th(source); th(sink);
		memset(h, 0, sizeof(h));
		memset(vh, 0, sizeof(vh));
		for (int i = 0; i < len; i++)
				buf[i].flow = 0;
		int ans = 0;
		while (h[source] != n)
				ans += sap(source, inf);
		return ans;
	}
}g;

void solve() {
    int n, m;
    cin >> m >> n;
    g.init(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        g.addCap(u, v, w);
    }
    int res = g.solve(0, n - 1);
    cout << res << endl;
}

int main() {
    freopen("ditch.in", "r", stdin);
    freopen("ditch.out", "w", stdout);
    solve();
    return 0;
}

