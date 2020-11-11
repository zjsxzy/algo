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

const int maxn = 105;
int n;
int x[maxn], y[maxn];
double d[maxn][maxn];

struct DisJointSet{
	int rank[maxn], parent[maxn];

	void init(int n) {
		for (int i = 0; i < n; i++) {
			rank[i] = 0;
			parent[i] = i;
		}
	}

	int Find(int x) {
		if (parent[x] == x) return x;
		return parent[x] = Find(parent[x]);
	}

	void Union(int x, int y) {
		x = Find(x);
		y = Find(y);

		if (x == y) return;

		if (rank[x] >= rank[y]) {
			parent[y] = x;
			if (rank[x] == rank[y])
				rank[x]++;
		}
		else {
			parent[x] = y;
		}
	}

	int count(int n) {
		int ret = 0;
		for (int i = 0; i < n; i++)
			ret += Find(i) == i;
		return ret;
	}
}uf;

double distance(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool check(double r) {
    int s = n, t = n + 1;
    uf.init(n + 2);
    for (int i = 0; i < n; i++) {
        if (100 - y[i] <= 2 * r) {
            uf.Union(s, i);
        }
        if (y[i] - (-100) <= 2 * r) {
            uf.Union(i, t);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (d[i][j] <= 2 * r) {
                uf.Union(i, j);
            }
        }
    }
    return uf.Find(s) == uf.Find(t);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            d[i][j] = d[j][i] = distance(x[i], y[i], x[j], y[j]);
        }
    }

    double lo = 0, hi = 200, res;
    while (hi - lo > 1e-5) {
        double mid = (lo + hi) / 2;
        if (check(mid)) {
            res = mid;
            hi = mid;
        } else {
            lo = mid;
        }
    }
    printf("%.4f\n", res);
    return 0;
}

