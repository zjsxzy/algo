#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

struct computer {
    int price, type, comp;
    computer(int p, int c, int t) {
        price = p;
        comp = c;
        type = t;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<computer> vec;
    for (int i = 0; i < n; i++) {
        int c, p;
        cin >> c >> p;
        vec.emplace_back(p, c, 1);
    }
    for (int i = 0; i < m; i++) {
        int c, p;
        cin >> c >> p;
        vec.emplace_back(p, c, 0);
    }
    sort(vec.begin(), vec.end(), [](const computer& a, const computer& b) {
        if (a.comp != b.comp) return a.comp > b.comp;
        return a.price < b.price;
    });
    multiset<int> order, cost;
    LL res = 0;
    for (auto& v: vec) {
        if (v.type == 0) {
            if (!order.empty()) {
                auto x = order.begin();
                if (v.price > *x) { // replace old
                    int t = *x;
                    res += (LL)(v.price - t);
                    order.erase(x);
                    order.insert(v.price);

                    if (!cost.empty()) {
                        auto y = cost.begin();
                        if (t > *y) {
                            res += (LL)(t - *y);
                            cost.erase(y);
                            order.insert(t);
                        }
                    }
                } else { // add new
                    if (!cost.empty()) {
                        auto y = cost.begin();
                        if (v.price > *y) {
                            res += (LL)(v.price - *y);
                            cost.erase(y);
                            order.insert(v.price);
                        }
                    }
                }
            } else { // add new
                if (!cost.empty()) {
                    auto y = cost.begin();
                    if (v.price > *y) {
                        res += (LL)(v.price - *y);
                        cost.erase(y);
                        order.insert(v.price);
                    }
                }
            }
        } else {
            cost.insert(v.price);
        }
        // cout << v.type << " " << v.comp << " " << v.price << " " << res << endl;
    }
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}
