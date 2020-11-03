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

vector<vector<pair<LL, LL> > > card;
LL res;
int n, m;

void search(int id, int t, LL total_cost, LL total_power) {
    // cout << id << " " << total_cost << " " << total_power << endl;
    if (id == n) {
        if (total_power > res) {
            res = total_power;
        }
        return;
    }
    // do not select card id
    search(id + 1, t, total_cost, total_power);
    // select card id
    for (int j = 0; j < card[id].size(); j++) {
        if (total_cost + card[id][j].first <= m) {
            search(id + 1, t + 1, total_cost + card[id][j].first, total_power + card[id][j].second);
        }
    }
}
int main() {
    int ts;
    cin >> ts;
    for (int cas = 1; cas <= ts; cas++) {
        cin >> m >> n;
        card.resize(n);
        for (int i = 0; i < n; i++) {
            int k, l;
            cin >> k >> l;
            vector<int> A(k + 1);
            vector<int> C(k);
            for (int j = 1; j <= k; j++) {
                cin >> A[j];
            }
            for (int j = 1; j <= k - 1; j++) {
                cin >> C[j];
            }
            LL cur_cost = 0;
            card[i].PB(MP(0, A[l]));
            for (int j = l + 1; j <= k; j++) {
                LL cost = cur_cost + C[j - 1];
                LL power = A[j];
                cur_cost += C[j - 1];
                card[i].PB(MP(cost, power));
            }
        }

        res = 0;
        search(0, 1, 0, 0);
        printf("Case #%d: %lld\n", cas, res);
        card.clear();
    }
    return 0;
}

