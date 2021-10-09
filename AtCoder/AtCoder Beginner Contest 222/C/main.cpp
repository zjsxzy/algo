#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 105;
string A[maxn];
int win[maxn];

int compare(char a, char b) {
    if (a == b) return 0;
    if (a == 'G' && b == 'C') return 1;
    if (a == 'C' && b == 'G') return -1;
    if (a == 'C' && b == 'P') return 1;
    if (a == 'P' && b == 'C') return -1;
    if (a == 'P' && b == 'G') return 1;
    if (a == 'G' && b == 'P') return -1;
    return 0;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> rank;
    memset(win, 0, sizeof(win));
    for (int i = 1; i <= 2 * n; i++) {
        cin >> A[i];
        rank.emplace_back(-win[i], i);
    }
    sort(rank.begin(), rank.end());
    for (int r = 0; r < m; r++) {
        for (int k = 1; k <= n; k++) {
            int x = 2 * k - 1, y = 2 * k;
            x = rank[x - 1].second;
            y = rank[y - 1].second;
            int cmp = compare(A[x][r], A[y][r]);
            if (cmp == 1) win[x]++;
            else if (cmp == -1) win[y]++;
        }
        vector<pair<int, int>> new_rank;
        for (int i = 1; i <= 2 * n; i++) {
            new_rank.emplace_back(-win[i], i);
        }
        rank = new_rank;
        sort(rank.begin(), rank.end());
    }
    for (auto p: rank) {
        cout << p.second << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

