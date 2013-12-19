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

const int MAXN = 500000 + 5;
int n, s[MAXN];
bool vst[MAXN];

int main() {
	int n;
	cin >> n;
	multiset<int> st;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	sort(s, s + n);
	int mid = (n & 1) ? (n + 1) / 2 : n / 2;
	for (int i = mid; i < n; i++)
		st.insert(s[i]);
	int ret = n;
	for (int i = 0; i < n; i++) {
		multiset<int>::iterator it = st.lower_bound(2 * s[i]);
		if (it != st.end()) {
			st.erase(it);
			ret--;
		}
	}
	cout << ret << endl;
	return 0;
}

