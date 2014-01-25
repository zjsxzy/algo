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

const int MAXN = 1 << 14;
const int inf = 0x3f3f3f3f;
struct Record {
	string name;
	int al, ar, b;
	Record() {}
	Record(const string &name, int al, int ar, int b) : name(name), al(al), ar(ar), b(b) {}
};
vector<Record> vp;
struct LotterPool {
	multiset<int> node[maxn << 2];

	void insert(int id, int b, int al, int ar, int l, int r, int rt) {
		if (al == l && ar == r) {
			node[rt].insert()
		}
	}

	void init(int pool) {
		for (int i = 0; i < MAXSIZE; i++)
			node[i].clear();
		vp.clear();
		this->pool = pool;
	}

	void add(const string &name, int al, int ar, int b) {
		pool += ar - al;
		vp.PB(Record(name, al, ar, b));
		insert(vp.size() - 1, b, al, ar, 0, MAXN, 0);
	}

	void darw(int a, int b) {
		int diff = find_d(b, a, 0, MAXN, 0);
		ids.clear();
		find_id(b + diff, a, 0, MAXN, 0);
		find_id(b - diff, a, 0, MAXN, 0);
		if (ids.size() == 0) {
			puts("0");
			return;
		}

		int prize = pool / ids.size();
		map<string, int> ans;
		pool -= ids.size() * prize;
		for (set<int>::const_iterator it = ids.begin(); it != ids.end(); it++) {
			ans[vp[*it].name] += prize;
			erase(*it, vp[*it].b, vp[*it].al, vp[*it].ar, 0, MAXN, 0);
		}
		printf("%d\n", ans.size());
		for (map<string, int>::const_iterator it = ans.begin(); it != ans.end(); it++) {
			printf("%s %d\n", it->first.c_str(), it->second);
		}
	}
};

int main() {
}

