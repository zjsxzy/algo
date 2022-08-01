#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, H, M;
    cin >> n >> H >> M;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (a[i].first > H || (a[i].first == H && a[i].second >= M)) {
            if (a[i].second < M) {
                cout << a[i].first - H - 1 << ' ' << a[i].second - M + 60 << endl;
            } else {
                cout << a[i].first - H << ' ' << a[i].second - M << endl;
            }
            return;
        }
    }
    int h = a[0].first + 24 - H;
    if (a[0].second < M) {
        cout << h - 1 << ' ' << a[0].second - M + 60 << endl;
    } else {
        cout << h << ' ' << a[0].second - M << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

