#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 25;
vector<int> num;
int n;
LL dp[maxn][15][2][2];

LL dfs(int pos, int first, bool limit, bool lead) {
    if (pos == n) {
        if (first) return 1;
        return 0;
    }
    if (dp[pos][first][limit][lead] != -1) return dp[pos][first][limit][lead];
    LL res = 0;
    for (int v = 0; v <= (limit ? num[pos] : 9); v++) {
        if (lead && v == 0) {
            res += dfs(pos + 1, v, limit && (v == num[pos]), true);
        } else {
            if (lead) res += dfs(pos + 1, v, limit && (v == num[pos]), false);
            else if (v < first) res += dfs(pos + 1, first, limit && (v == num[pos]), false);
        }
    }
    return dp[pos][first][limit][lead] = res;
}

LL f(string s) {
	memset(dp, -1, sizeof(dp));
	n = s.size();
	num.clear();
	for (auto c: s) num.push_back(c - '0');
	LL res = dfs(0, 11, true, true);
	return res;
}

void solve() {
    LL L, R;
    cin >> L >> R;
    L--;
    string l = to_string(L), r = to_string(R);
    cout << f(r) - f(l) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}