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

const int MAXN = 55;
const int MOD = 998244353;
int a[MAXN][MAXN];
int N, K;

struct DisJointSet{
	int rank[MAXN], parent[MAXN];

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
}f1, f2;

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }


    f1.init(N);
    f2.init(N);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {

            bool flag = true;
            for (int k = 0; k < N; k++) {
                if (a[i][k] + a[j][k] > K) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
            //    cout << i << " " << j << endl;
                f1.Union(i, j);
            }

            flag = true;
            for (int k = 0; k < N; k++) {
                if (a[k][i] + a[k][j] > K) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
            //    cout << i << " " << j << endl;
                f2.Union(i, j);
            }
        }
    }

    vector<int> cntr(N), cntc(N);
    for (int i = 0; i < N; i++) {
        cntr[f1.Find(i)]++;
        cntc[f2.Find(i)]++;
    }
    LL res = 1;
    for (int i = 0; i < N; i++) {
        if (cntr[i] > 0) {
            for (int k = 2; k <= cntr[i]; k++) {
                res = res * k % MOD;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (cntc[i] > 0) {
            for (int k = 2; k <= cntc[i]; k++) {
                res = res * k % MOD;
            }
        }
    }
    cout << res << endl;

    return 0;
}

