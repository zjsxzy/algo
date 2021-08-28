/*
ID: frankzh1
TASK: spin
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

struct wheel {
    int sp, num;
    vector<int> st, len;
    wheel(int sp, int num) {
        this->sp = sp;
        this->num = num;
        st.resize(num);
        len.resize(num);
    }
};

void solve() {
    int n = 5;
    vector<wheel> w;
    for (int i = 0; i < n; i++) {
        int sp, num;
        cin >> sp >> num;
        w.emplace_back(sp, num);
        for (int j = 0; j < w[i].num; j++) {
            cin >> w[i].st[j] >> w[i].len[j];
        }
    }
    for (int t = 0; t <= 360; t++) {
        vector<int> gap(361);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < w[i].num; j++) {
                for (int k = 0; k <= w[i].len[j]; k++) {
                    gap[(w[i].st[j] + k) % 360]++;
                }
                w[i].st[j] = (w[i].st[j] + w[i].sp) % 360;
            }
        }
        for (int i = 0; i <= 360; i++) {
            if (gap[i] == 5) {
                cout << t << endl;
                return;
            }
        }
    }
    cout << "none" << endl;
}

int main() {
    freopen("spin.in", "r", stdin);
    freopen("spin.out", "w", stdout);
    solve();
    return 0;
}

