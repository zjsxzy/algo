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

const int manx = 105;
int n, T;
vector<pair<int, pair<int, int> > > vec;
string health;

bool check(int st, int k) {
    string cur(n, '0');
    cur[st - 1] = '1';
    vector<int> cnt(n);
    for (auto shake : vec) {
        int x = shake.second.first - 1, y = shake.second.second - 1;
        if (cur[x] == '1') cnt[x]++;
        if (cur[y] == '1') cnt[y]++;
        if (cur[x] == '0') {
            if (cur[y] == '1' && cnt[y] <= k) {
                cur[x] = '1';
            }
        }
        if (cur[y] == '0') {
            if (cur[x] == '1' && cnt[x] <= k) {
                cur[y] = '1';
            }
        }
    }
    return cur == health;
}

void solve() {
    cin >> n >> T;
    cin >> health;
    for (int i = 0; i < T; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        vec.push_back({t, {x, y}});
    }
    sort(vec.begin(), vec.end());

    int patient_num = 0, Kmin = n + 1, Kmax = 0;
    for (int st = 1; st <= n; st++) {
        bool flag = false;
        for (int k = 0; k <= n + 1; k++) {
            if (check(st, k)) {
                flag = true;
                Kmin = min(Kmin, k);
                Kmax = max(Kmax, k);
            }
        }
        patient_num += flag;
    }
    cout << patient_num << " " << Kmin << " ";
    if (Kmax == n + 1) cout << "Infinity" << endl;
    else cout << Kmax << endl;
}

int main() {
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
    solve();
    return 0;
}

