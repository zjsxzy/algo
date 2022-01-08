#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    LL K;
    cin >> n >> K;
    vector<LL> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    vector<tuple<LL, int, int>> query;
    for (int i = 0; i < n; i++) {
        query.push_back(make_tuple(y[i]- K, 0, i));
        query.push_back(make_tuple(y[i], 1, i));
        query.push_back(make_tuple(y[i] + K, 2, i));
    }
    sort(query.begin(), query.end());
    set<pair<LL, int>> st;
    vector<pair<int, int>> ans;
    for (int i = 0; i < n * 3; i++) {
        int type = get<1>(query[i]);
        int id = get<2>(query[i]);
        if (type == 0) {
            st.insert({x[id], id});
        } else if (type == 1) {
            auto it = st.lower_bound({x[id] - K, -1});
            while (it != st.end()) {
                LL X = (*it).first;
                if (X > x[id] + K) {
                    break;
                }
                int id2 = (*it).second;
                if ((x[id] - x[id2]) * (x[id] - x[id2]) + (y[id] - y[id2]) * (y[id] - y[id2]) <= K * K && id < id2) {
                    ans.push_back({id, id2});
                }
                it++;
            }
        } else if (type == 2) {
            st.erase({x[id], id});
        }
    }
    sort(ans.begin(), ans.end());
    int m = ans.size();
    cout << m << endl;
    for (int i = 0; i < m; i++) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

