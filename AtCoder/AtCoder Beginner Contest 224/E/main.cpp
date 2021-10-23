#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 200005;
struct Cell {
    int r, c, a, idx, ans;
}cell[maxn];
int h, w, n;
int row[maxn], col[maxn];

bool cmp1(const Cell& A, const Cell& B) {
    return A.a > B.a;
}

bool cmp2(const Cell& A, const Cell& B) {
    return A.idx < B.idx;
}

void solve() {
    cin >> h >> w >> n;
    for (int i = 0; i < n; i++) {
        cin >> cell[i].r >> cell[i].c >> cell[i].a;
        cell[i].idx = i;
    }
    sort(cell, cell + n, cmp1);
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    for (int i = 0; i < n; ) {
        int val = cell[i].a, j = i + 1;
        while (cell[i].a == cell[j].a) {
            j++;
        }
        for (int k = i; k < j; k++) {
            cell[k].ans = max(row[cell[k].r], col[cell[k].c]);
        }
        for (int k = i; k < j; k++) {
            row[cell[k].r] = max(row[cell[k].r], cell[k].ans + 1);
            col[cell[k].c] = max(col[cell[k].c], cell[k].ans + 1);
        }
        i = j;
    }
    sort(cell, cell + n, cmp2);
    for (int i = 0; i < n; i++) {
        cout << cell[i].ans << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

