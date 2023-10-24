#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 998244353;
vector<int> num;
int n;
int dp[205][2005][2][2];

int dfs(int pos, int last, int sum, bool limit, bool lead) {
    if (pos == n) {
        if (!lead && last != 0 && sum % last == 0) return 1;
        return 0;
    }
    if (dp[pos][sum][limit][lead] != -1) return dp[pos][sum][limit][lead];
    int res = 0;
    for (int v = 0; v <= (limit ? num[pos] : 9); v++) {
        if (lead && v == 0) {
            res += dfs(pos + 1, v, sum + v, limit && (v == num[pos]), true);
            res %= mod;
        } else {
            res += dfs(pos + 1, v, sum + v, limit && (v == num[pos]), false);
            res %= mod;
        }
    }
    return dp[pos][sum][limit][lead] = res;
}
    
int f(string s) {
    memset(dp, -1, sizeof(dp));
    n = s.size();
    num.clear();
    for (auto c: s) num.push_back(c - '0');
    int res = dfs(0, 11, 0, true, true);
    return res;
}

bool check(string s) {
    int sz = s.size();
    if (s[sz - 1] == '0') return false;
    int sum = 0;
    for (int i = 0; i < sz; i++) {
        sum += s[i] - '0';
    }
    return sum % (s[sz - 1] - '0') == 0;
}

void solve() {
    string l, r;
    cin >> l >> r;
    cout << (f(r) - f(l) + check(l) + mod) % mod << endl;
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