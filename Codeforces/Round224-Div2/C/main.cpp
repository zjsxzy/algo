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

const int MAXN = 100000 + 5;
int n;
LL card[MAXN], diff[MAXN];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> card[i];
	if (n == 1) {
		puts("-1");
		return 0;
	}
	sort(card, card + n);
	map<LL, int> cnt;
	for (int i = 0; i < n - 1; i++) {
		diff[i] = card[i + 1] - card[i];
		cnt[diff[i]]++;
	}
	if (cnt.size() == 1) {
		set<int> ans;
		if (n == 2 && diff[0] % 2 == 0) {
			ans.insert(card[0] - diff[0]);
			ans.insert(card[0] + diff[0] / 2);
			ans.insert(card[n - 1] + diff[0]);
		} else {
			ans.insert(card[0] - diff[0]);
			ans.insert(card[n - 1] + diff[0]);
		}
		cout << ans.size() << endl;
		set<int>::iterator it = ans.begin();
		cout << *it;
		it++;
		for (; it != ans.end(); it++) {
			cout << " " << *it;
		}
		cout << endl;
	} else if (cnt.size() == 2) {
		bool flag = false;
		LL d, a;
		for (map<LL, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
			if (it->second == 1) {
				d = it->first;
				flag = true;
			} else {
				a = it->first;
			}
		}
		if (!flag) {
			puts("0");
		} else {
			if (2 * a != d) {
				puts("0");
			} else {
				cout << 1 << endl;
				for (int i = 0; i < n - 1; i++)
					if (diff[i] == d) {
						cout << card[i] + a << endl;
						break;
					}
			}
		}
	} else {
		puts("0");
	}
}

