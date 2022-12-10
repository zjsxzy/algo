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

const int maxn = 35;
int n, m;
int p[maxn];
map<vector<int>, double> dp;

int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}

double DP(vector<int> state) {
	if (dp.count(state)) return dp[state];
	double &res = dp[state];
	double sum = n * (n - 1) / 2;
	double same = 0;
	if (state.size() == 1) return res = 0;
	for (int i = 0; i < SZ(state); i++) {
		for (int j = 0; j < i + 1; j++) {
			if (i == j) same += (state[i] * (state[i] - 1)) / 2 / sum;
			else {
				vector<int> newstate = state;
				newstate[i] += newstate[j];
				swap(newstate[j], newstate[SZ(newstate) - 1]);
				newstate.pop_back();
				sort(newstate.begin(), newstate.end());
				res += (double)state[i] * state[j] / sum * DP(newstate);
			}
		}
	}
	res = (res + 1) / (1 - same);
	return res;
}

int main() {
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 1; i <= n; i++) p[i] = i;
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			p[find(a)] = find(b);
		}

		vector<int> state;
		vector<int> cnt(n + 1);
		for (int i = 1; i <= n; i++)
			cnt[find(i)]++;
		FOREACH(it, cnt) {
			if (*it == 0) continue;
			state.PB(*it);
		}
		sort(state.begin(), state.end());
		double res = DP(state);
		printf("%.6f\n", res);
	}
	return 0;
}
