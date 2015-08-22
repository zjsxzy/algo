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

const int MAXN = 11000000;
int n;
char str[MAXN];
vector<pair<char, int> > p;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		p.clear();
		scanf("%d\n%s\n", &n, str);
		int cnt = 1;
		char curr = str[0];
		for (int i = 1; i < n; i++) {
			if (str[i] != curr) {
				p.PB(MP(curr, cnt));
				curr = str[i];
				cnt = 1;
			} else {
				cnt++;
			}
		}
		p.PB(MP(curr, cnt));
		// for (int i = 0; i < p.size(); i++) {
		// 	cout << p[i].first << " " << p[i].second << endl;
		// }
		bool flag = false;
		for (int i = 0; i + 2 < p.size(); i++) {
			if (p[i].first + 1 == p[i + 1].first && p[i].first + 2 == p[i + 2].first) {
				if (p[i].second >= p[i + 1].second && p[i + 1].second <= p[i + 2].second) {
					flag = true;
					break;
				}
			}
		}
		puts(flag ? "YES" : "NO");
	}
	return 0;
}

