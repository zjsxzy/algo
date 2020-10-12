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

const int maxn = 200005;
struct BinaryIndexTree {
	int N;
	int C[maxn];

	void init(int N) {
		this->N = N;
		memset(C, 0, sizeof(C));
	}

	int lowbit(int x) {
		return x & (-x);
	}

	void add(int x, int num) {
		for (int i = x; i <= N; i += lowbit(i))
			C[i] += num;
	}

	int sum(int x) {
		int ret = 0;
		for (int i = x; i > 0; i -= lowbit(i))
			ret += C[i];
		return ret;
	}
}bit;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<char, vector<int> > mp;
    for (int i = n - 1; i >= 0; i--) {
        mp[s[i]].push_back(i + 1);
    }
    string t = s;
    reverse(t.begin(), t.end());
    // reweight
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = mp[t[i]].back();
        mp[t[i]].pop_back();
    }
    /*
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    */

    // 对a[]求逆序对
    bit.init(n);
    long long res = 0;
    for (int i = 0; i < n; i++) {
        res += i - bit.sum(a[i]);
        bit.add(a[i], 1);
    }
    cout << res << endl;
    return 0;
}
