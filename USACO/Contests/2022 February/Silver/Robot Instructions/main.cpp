#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

struct hsh {
	size_t operator()(const pair<LL, LL> &p) const {
		return p.first * 239 + p.second;
	}
};

void solve() {
    int n;
    cin >> n;
    LL gx, gy;
    cin >> gx >> gy;
    vector<LL> dx(n), dy(n);
    for (int i = 0; i < n; i++) {
        cin >> dx[i] >> dy[i];
    }

    int half = n / 2;
    int ls = half, rs = n - half;
    vector<pair<LL, LL>> lsum(1 << ls);
    for (int i = 0; i < (1 << ls); i++) {
        for (int j = 0; j < ls; j++) {
            if ((i >> j) & 1) {
                lsum[i].first = lsum[i ^ (1 << j)].first + dx[j];
                lsum[i].second = lsum[i ^ (1 << j)].second + dy[j];
            }
        }
    }
    vector<pair<LL, LL>> rsum(1 << rs);
    for (int i = 0; i < (1 << rs); i++) {
        for (int j = 0; j < rs; j++) {
            if ((i >> j) & 1) {
                rsum[i].first = rsum[i ^ (1 << j)].first + dx[half + j];
                rsum[i].second = rsum[i ^ (1 << j)].second + dy[half + j];
            }
        }
    }

    unordered_map<pair<LL, LL>, map<int, int>, hsh> lmp;
    for (int i = 0; i < (1 << ls); i++) {
        int s = __builtin_popcount(i);
        lmp[{lsum[i].first, lsum[i].second}][s]++;
    }

    vector<LL> ans(n + 1);
    for (int i = 0; i < (1 << rs); i++) {
        int s = __builtin_popcount(i);
        pair<LL, LL> t = {gx - rsum[i].first, gy - rsum[i].second};
        if (lmp.find(t) != lmp.end()) {
            for (auto &[k, cnt]: lmp[t]) {
                ans[s + k] += cnt;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
}

int main() {
    solve();
    return 0;
}

