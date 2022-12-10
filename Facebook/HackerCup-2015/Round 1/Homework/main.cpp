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

const int MAXN = 10000000 + 5;
int cnt[MAXN];
vector<int> prime;
map<int, vector<int> > mp;
void getPrime() {
	memset(cnt, 0, sizeof(cnt));
	for (int i = 2; i <= MAXN - 5; i++) {
		if (!cnt[i]) {
			for (int j = 1; i * j <= MAXN - 5; j++) {
				cnt[i * j]++;
			}
		}
	}
	for (int i = 2; i <= MAXN - 5; i++) {
		mp[cnt[i]].PB(i);
	}
}
int getAns(int A, int B, int K) {
	if (mp.find(K) == mp.end()) {
		return 0;
	}
	vector<int> vec = mp[K];
	vector<int>::iterator lo = lower_bound(vec.begin(), vec.end(), A);
	vector<int>::iterator up = upper_bound(vec.begin(), vec.end(), B);
	if (up == vec.begin()) {
		return 0;
	} else {
		return up - lo;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	// freopen("in.txt", "r", stdin);
#endif
    int ts;
    scanf("%d", &ts);
    getPrime();
    for (int cas = 1; cas <= ts; cas++) {
        printf("Case #%d: ", cas);
		int A, B, K;
		scanf("%d%d%d", &A, &B, &K);
		printf("%d\n", getAns(A, B, K));
    }
	return 0;
}

