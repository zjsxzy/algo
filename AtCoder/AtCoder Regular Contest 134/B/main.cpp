#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<set<int>> vec(26);
    for (int i = 0; i < n; i++) {
        vec[s[i] - 'a'].insert(i);
    }
    string t = s;
    int j = 0, last = n;
    for (int i = 0; i < n; i++) {
        bool flag = false;
        int pos = -1;
        for (int c = 0; c < s[i] - 'a' && !flag; c++) {
            if (vec[c].size() > 0) {
                auto it = vec[c].lower_bound(last);
                if (it != vec[c].begin()) {
                    it--;
                    pos = *it;
                    if (i < pos) {
                        last = pos;
                        flag = true;
                    }
                }
            }
        }
        if (flag) {
            // cout << i << " " << pos << endl;
            swap(t[i], t[pos]);
        }
    }
    cout << t << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

