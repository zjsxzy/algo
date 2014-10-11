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

const int maxn = 200000 + 5;
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
}djs;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	djs.init(2 * n);
	map<string, int> name;
	int person = 0;
	while (n--) {
		int op;
		string s1, s2;
		cin >> op >> s1 >> s2;
		if (name.find(s1) == name.end()) {
			name[s1] = person++;
		}
		if (name.find(s2) == name.end()) {
			name[s2] = person++;
		}
		int idx1 = name[s1], idx2 = name[s2];
		if (op == 0) {
			djs.Union(idx1, idx2);
		} else {
			if (djs.Find(idx1) == djs.Find(idx2)) {
				cout << "yes" << endl;
			} else {
				cout << "no" << endl;
			}
		}
	}	
	return 0;
}

