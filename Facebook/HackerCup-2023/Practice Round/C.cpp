#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve(int cs) {
    cout << "Case #" << cs << ": ";
    int n;
    cin >> n;
    vector<int> a(2 * n - 1);
    multiset<int> st;
    for (auto& x: a) {
        cin >> x;
        st.insert(x);
    }
    sort(a.begin(), a.end());
    if (n == 1) {
        cout << a[0] << endl;
        return;
    }
    const int inf = 2e9 + 1;
    auto f = [&](int k) {
        multiset<int> s = st;
        int res = -1;
        while (!s.empty()) {
            auto x = s.begin();
            int val = *x;
            s.erase(x);
            if (s.count(k - val)) s.extract(k - val);
            else if (res != -1) return inf;
            else res = k - val; 
        }
        if (res > 0) return res;
        return inf;
    };
    int res = f(a[0] + a.back());
    res = min(res, f(a[1] + a.back()));
    res = min(res, f(a[0] + a[2 * n - 3]));
    if (res == inf) res = -1;
    cout << res << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve(t);
    }
    return 0;
}