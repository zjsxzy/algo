#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

#define th(x) this->x = x
const int MAXN = 2000000 + 10;
const int MAXM = 4000000 + 10;
const int inf = 0x3f3f3f3f;
struct Nod
{
	int b, next;
	LL cap, flow;
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
	LL sap(const int idx, const int maxCap)
	{
		if (idx == sink)
				return maxCap;
		LL l = maxCap, d;
        int minH = n;
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
	LL solve(int source, int sink)
	{
		if (source == sink) return inf;
		th(source); th(sink);
		memset(h, 0, sizeof(h));
		memset(vh, 0, sizeof(vh));
		for (int i = 0; i < len; i++)
				buf[i].flow = 0;
		LL ans = 0;
		while (h[source] != n)
				ans += sap(source, inf);
		return ans;
	}
}sap;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    sap.init(2 * n + 2);
    int source = 2 * n, sink = 2 * n + 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sap.addCap(source, i, a[i]);
        sap.addCap(i, n + i, a[i]);
        sap.addCap(i, n + (i + 1) % n, a[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        sap.addCap(n + i, sink, b[i]);
    }
    LL res = sap.solve(source, sink);
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}

