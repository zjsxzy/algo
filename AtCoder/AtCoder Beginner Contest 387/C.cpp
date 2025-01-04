#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 25;
vector<int> num;
int n;
LL dp[maxn][15][2][2];

LL dfs(int pos, int first, bool limit, bool lead) {
    if (lead) first = 0;
    if (pos == n) {
        return 1;
    }
    if (dp[pos][first][limit][lead] != -1) return dp[pos][first][limit][lead];
    LL res = 0;
    int up = (limit ? num[pos] : 9);
    if (!lead) up = min(up, first - 1);
    for (int v = 0; v <= up; v++) {
        res += dfs(pos + 1, lead ? v : first, limit && (v == num[pos]), lead && (v == 0));
        // if (lead && v == 0) {
            // res += dfs(pos + 1, lead ? v : first, limit && (v == num[pos]), true);
        // } else {
            // res += dfs(pos + 1, lead ? v : first, limit && (v == num[pos]), false);
        // }
    }
    return dp[pos][first][limit][lead] = res;
}

LL f(string s) {
    if (s == "9") return 0;
	memset(dp, -1, sizeof(dp));
	n = s.size();
	num.clear();
	for (auto c: s) num.push_back(c - '0');
	LL res = dfs(0, 0, true, true);
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