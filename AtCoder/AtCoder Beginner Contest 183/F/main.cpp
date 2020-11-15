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

const int maxn = 200005;
int n, q;
int c[maxn];

struct DisJointSet{
	int rank[maxn], parent[maxn];
    map<int, int> mp[maxn];

	void init(int n) {
		for (int i = 0; i < n; i++) {
			rank[i] = 0;
			parent[i] = i;
            mp[i][c[i]] = 1;
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
            for (auto it : mp[y]) {
                mp[x][it.first] += it.second;
            }
			parent[y] = x;
			if (rank[x] == rank[y])
				rank[x]++;
		}
		else {
            for (auto it : mp[x]) {
                mp[y][it.first] += it.second;
            }
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

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    uf.init(n);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            uf.Union(a, b);
        } else {
            int x, y;
            cin >> x >> y;
            x--;
            int f = uf.Find(x);
            cout << uf.mp[f][y] << endl;
        }
    }
    return 0;
}

