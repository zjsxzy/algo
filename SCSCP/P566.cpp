#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 105;
int n, k;
int g[MAXN][MAXN];

void solve() {
    cin >> n >> k;
    vector<int> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++) {
            g[i][j] = str[j] == '1' ? 1 : 0;
        }
    }
    vector<int> clique;
    clique.push_back(0);
    for (int s = 1; s < (1 << n); s++) {
        int bits = 0, sum = 0;
        vector<int> nodes;
        for (int i = 0; i < n; i++) {
            if (s & (1 << i)) {
                nodes.push_back(i);
                bits++;
                sum += w[i];
            }
        }
        if (bits == 1) {
            clique.push_back(sum);
            continue;
        }
        bool flag = true;
        for (int i = 0; i < nodes.size() && flag; i++) {
            for (int j = i + 1; j < nodes.size() && flag; j++) {
                int u = nodes[i], v = nodes[j];
                if (!g[u][v]) flag = false;
            }
        }
        if (flag) {
            clique.push_back(sum);
        }
    }
    if (k <= clique.size()) {
        cout << clique[k - 1] << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    solve();
    return 0;
}

