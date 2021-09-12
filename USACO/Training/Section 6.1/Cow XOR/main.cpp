/*
ID: frankzh1
TASK: cowxor
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 750005;
struct Trie {
    struct Tnode {
        int next[2];
        int terminate;
    }chd[MAXN];
    int size;

    void init() {
        size = 1;
        memset(chd[0].next, 0, sizeof(chd[0].next));
        chd[0].terminate = -1;
    }

    void insert(int x, int id) {
        int p = 0;
        for (int i = 20; i >= 0; i--) {
            int c = (x >> i) & 1;
            if (!chd[p].next[c]) {
                memset(chd[size].next, 0, sizeof(chd[size].next));
                chd[size].terminate = -1;
                chd[p].next[c] = size++;
            }
            p = chd[p].next[c];
        }
        chd[p].terminate = id;
    }

    int find(int x) {
        int p = 0;
        for (int i = 20; i >= 0; i--) {
            int c = (x >> i) & 1;
            if (chd[p].next[c ^ 1]) {
                p = chd[p].next[c ^ 1];
            } else {
                p = chd[p].next[c];
            }
        }
        return chd[p].terminate;
    }
}trie;

void solve() {
    trie.init();
    int n;
    cin >> n;
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        sum[i] = sum[i - 1] ^ x;
    }
    int res = 0, l = 1, r = 1;
    for (int i = 1; i <= n; i++) {
        if (trie.size > 1) {
            int t = trie.find(sum[i]);
            int val = sum[i] ^ sum[t];
            if (val > res) {
                res = val;
                l = t + 1;
                r = i;
            }
        } else { // i == 1
            res = sum[i];
            l = r = 1;
        }
        trie.insert(sum[i], i);
    }
    cout << res << " " << l << " " << r << endl;
}

int main() {
    freopen("cowxor.in", "r", stdin);
    freopen("cowxor.out", "w", stdout);
    solve();
    return 0;
}

