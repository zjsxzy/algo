#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct ant {
    int pos, dir, idx;
    ant() {}
    ant(int p, int d, int i) : pos(p), dir(d), idx(i) {}
};

void solve() {
    int n, L;
    cin >> n >> L;
    vector<ant> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].pos >> a[i].dir;
        a[i].idx = i;
    }
    sort(a.begin(), a.end(), [&](ant A, ant B) {
        return A.pos < B.pos;
    });
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++) {
        if (a[i].dir == 0) {
            vec.emplace_back(a[i].pos, 0);
        } else {
            vec.emplace_back(L - a[i].pos, 1);
        }
    }
    sort(vec.begin(), vec.end());
    vector<pair<int, int>> ti(n);
    int l = 0, r = n - 1;
    for (auto p: vec) {
        if (p.second == 0) {
            int id = a[l].idx;
            ti[id].first = p.first;
            l++;
        } else {
            int id = a[r].idx;
            ti[id].first = p.first;
            r--;
        }
    }
    for (int i = 0; i < n; i++) {
        ti[i].second = i;
    }
    sort(ti.begin(), ti.end());
    for (int i = 0; i < n; i++) cout << ti[i].second + 1 << ' ';
    cout << endl;
}

int main() {
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       cout << "Case #" << t << ": ";
       solve();
   }
   return 0;
}

