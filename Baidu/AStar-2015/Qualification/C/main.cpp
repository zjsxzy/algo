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

int n, m;
vector<vector<int> > ip;
set<vector<int> > st;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
    int ts; cin >> ts;
    for (int cas = 1; cas <= ts; cas++) {
        printf("Case #%d:\n", cas);
        cin >> n >> m;
		ip.clear();
        for (int i = 0; i < n; i++) {
			int a, b, c, d;
			scanf("%d.%d.%d.%d\n", &a, &b, &c, &d);
			vector<int> temp;
			temp.PB(a); temp.PB(b); temp.PB(c); temp.PB(d);
			ip.PB(temp);
        }
		for (int i = 0; i < m; i++) {
			int a, b, c, d;
			scanf("%d.%d.%d.%d\n", &a, &b, &c, &d);
			st.clear();
			for (int j = 0; j < n; j++) {
				int aa = a & ip[j][0];
				int bb = b & ip[j][1];
				int cc = c & ip[j][2];
				int dd = d & ip[j][3];
				vector<int> temp;
				temp.PB(aa); temp.PB(bb); temp.PB(cc); temp.PB(dd);
				// cout << aa << " " << bb << " " << cc << " " << dd << endl;
				// st.insert(to_string(aa) + to_string(bb) + to_string(cc) + to_string(dd));
				st.insert(temp);
			}
			cout << st.size() << endl;
		}
    }
	return 0;
}

