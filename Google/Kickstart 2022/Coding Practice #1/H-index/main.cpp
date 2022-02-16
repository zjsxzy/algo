#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 100005;
// index from 0
struct Fenwick{
    vector<int> tree;
    int n;
    Fenwick() {}
    Fenwick(int _n) {
        n = _n;
        tree.assign(n, 0);
    }
    void upd(int pos, int val) {
        for (; pos < n; pos |= pos + 1) {
            tree[pos] += val;
        }
    }
    int get(int r) {
        int ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans += tree[r];
        }
        return ans;
    }
    int get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
};

void solve(int cs) {
	int n;
	cin >> n;
	Fenwick tree(maxn);
	cout << "Case #" << cs << ": ";
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		tree.upd(x, 1);
		int lo = 0, hi = i + 1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (i + 1 - tree.get(mid - 1) >= mid) lo = mid + 1;
			else hi = mid - 1;
		}
		cout << " " << hi;
	}
	cout << endl;
}

int main() {
	int ts;
	cin >> ts;
	for (int cs = 1; cs <= ts; cs++) {
		solve(cs);
	}
    return 0;
}

