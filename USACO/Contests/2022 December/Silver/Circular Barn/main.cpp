#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 5000005;
int composite[maxn];
int max_mod[4] = {2, 1, 2, 3};
int min_turns[maxn] = {0, 1};

void prepare() {
    for (int i = 2; i < maxn; i++) {
        if (!composite[i]) {
            for (int j = i + i; j < maxn; j += i) {
                composite[j] = true;
            }
            max_mod[i % 4] = i;
        }
        min_turns[i] = (i - max_mod[i % 4]) / 2 + 1;
    }
}

void solve() {
    int n;
    cin >> n;
    int ans = INT_MAX;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (min_turns[a[i]] / 2 < ans / 2) ans = min_turns[a[i]];
    }
    if (ans & 1) cout << "Farmer John" << endl;
    else cout << "Farmer Nhoj" << endl;
}

int main() {
    prepare();
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}